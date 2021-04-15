/* codgen.c       Generate Assembly Code for x86         07 May 18   */

/* Copyright (c) 2018 Gordon S. Novak Jr. and The University of Texas at Austin
    */

/* Starter file for CS 375 Code Generation assignment.           */
/* Written by Gordon S. Novak Jr.                  */

/* This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License (file gpl.text) for more details.
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "symtab.h"
#include "lexan.h"
#include "genasm.h"
#include "codegen.h"
#include "pprint.h"

void genc(TOKEN code);

/* Set DEBUGGEN to 1 for debug printouts of code generation */
#define DEBUGGEN 0

#define REGISTERSNUM 32

int nextlabel;    /* Next available label number */
int stkframesize;   /* total stack frame size */
int registerTable[REGISTERSNUM];
int intOP[32];
int realOP[32];
int pointOP[32];
int jumpOP[32];

/* Top-level entry for code generator.
   pcode    = pointer to code:  (program foo (output) (progn ...))
   varsize  = size of local storage in bytes
   maxlabel = maximum label number used so far
Add this line to the end of your main program:
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
The generated code is printed out; use a text editor to extract it for
your .s file.
         */

void gencode(TOKEN pcode, int varsize, int maxlabel)
  {  
    for (int i = 0; i<32; i++) {
        registerTable[i] = 0;
        intOP[i] = -1;
        realOP[i] = -1;
        pointOP[i] = -1;
    }
    
    intOP[PLUSOP] = ADDL;
    intOP[MINUSOP] = SUBL;
    intOP[TIMESOP] = IMULL;
    intOP[DIVIDEOP] = DIVL;
    intOP[ANDOP] = ANDL;
    intOP[OROP] = ORL;
    intOP[NOTOP] = NEGL;
    intOP[EQOP] = CMPL;
    intOP[LEOP] = CMPL;
    intOP[LTOP] = CMPL;
    intOP[GEOP] = CMPL;
    intOP[GTOP] = CMPL;
    intOP[NEOP] = CMPL;
    
    realOP[PLUSOP] = ADDSD;
    realOP[MINUSOP] = SUBSD;
    realOP[TIMESOP] = MULSD;
    realOP[DIVIDEOP] = DIVSD;
    realOP[NOTOP] = NEGSD;
    realOP[EQOP] = CMPSD;
    realOP[LEOP] = CMPSD;
    realOP[LTOP] = CMPSD;
    realOP[GEOP] = CMPSD;
    realOP[GTOP] = CMPSD;
    realOP[NEOP] = CMPSD;
    
    pointOP[PLUSOP] = ADDQ;
    pointOP[MINUSOP] = SUBQ;
    pointOP[TIMESOP] = IMULQ;
    pointOP[ANDOP] = ANDQ;
    pointOP[OROP] = ORQ;
    pointOP[NOTOP] = NEGQ;
    pointOP[EQOP] = CMPQ;
    pointOP[LEOP] = CMPQ;
    pointOP[LTOP] = CMPQ;
    pointOP[GEOP] = CMPQ;
    pointOP[GTOP] = CMPQ;
    pointOP[NEOP] = CMPQ;

    jumpOP[EQOP] = JE;
    jumpOP[NEOP] = JNE;
    jumpOP[LTOP] = JL;
    jumpOP[LEOP] = JLE;
    jumpOP[GTOP] = JG;
    jumpOP[GEOP] = JGE;
     TOKEN name, code;
     name = pcode->operands;
     code = name->link->link;
     nextlabel = maxlabel + 1;
     stkframesize = asmentry(name->stringval,varsize);
     genc(code);
     asmexit(name->stringval);
  }


/* Trivial version: always returns RBASE + 0 */
/* Get a register.   */
/* Need a type parameter or two versions for INTEGER or REAL */
int getreg(int kind)
  {
   
    if(kind == REAL || kind == STRINGTYPE || kind == POINTER) {
      for(int i = FBASE; i <= FMAX; i++) {
        if(registerTable[i] == 0) {
          registerTable[i] = 1;
          return i;
        }
      }
    } else if(kind == INTEGER || kind == BOOLETYPE) {
      for(int i = RBASE; i <= RMAX; i++) {
        if(registerTable[i] == 0) {
          registerTable[i] = 1;
          return i;
        }
      }
    }
    printf("get reg failed\n");
    return -1;
  }



int arefgeneral (TOKEN code) {
    int tempreg = genarith(code->operands);
    int offs = code->operands ->link->intval;
    int returnedReg = 0;
    if (code->basicdt == INTEGER) {
        returnedReg = getreg(0);
        asmldr(MOVL, offs, tempreg, returnedReg, "^.");
      
    } else if (code->basicdt == REAL)
    {
        returnedReg = getreg(REAL);
        asmldr(MOVSD, offs, tempreg, returnedReg, "^.");
        
    } else if (code->basicdt == POINTER)
    {
        returnedReg = getreg(0);
        asmldr(MOVQ, offs, tempreg, returnedReg, "^.");
    
    }
    registerTable[tempreg] = 0;
    return returnedReg;   
}

int arefidentity (TOKEN code, int storereg) {
    int tempreg = genarith(code->operands -> link);
    int offs = code->operands ->symentry -> offset -stkframesize;
 
    if (code->basicdt == INTEGER) {
      
        asmop(CLTQ);
        asmstrr(MOVL, storereg ,offs,  tempreg, code->operands->stringval);
      
    } else if (code->basicdt == REAL)
    {
     
        asmop(CLTQ);
        asmstrr(MOVSD, storereg ,offs,  tempreg, code->operands->stringval);
        
    } else if (code->basicdt == POINTER)
    {
        asmop(CLTQ);
        asmstrr(MOVQ, storereg ,offs, tempreg, code->operands->stringval);
    
    }
    registerTable[tempreg] = 0;
    return storereg;
}

int arefnum(TOKEN code, int storereg) {
    int tempreg = genarith(code->operands);
    int offs = code->operands ->link->intval;

    if (code->basicdt == INTEGER) {
   
        asmstr(MOVL, storereg, code->operands->link->intval, tempreg, "^. ");
      
    } else if (code->basicdt == REAL)
    {

          asmstr(MOVSD, storereg, code->operands->link->intval, tempreg, "^. ");
        
    } else if (code->basicdt == POINTER)
    {

         asmstr(MOVQ, storereg, code->operands->link->intval, tempreg, "^. ");
    
    }
    registerTable[tempreg] = 0;
    return storereg; 
}


int genaref(TOKEN code, int storereg){
    int reg;
    if(storereg < 0){
        return arefgeneral(code);
    }else if(code->operands->tokentype == IDENTIFIERTOK){
       return arefidentity(code, storereg);
    }else if(code->operands ->link->tokentype == NUMBERTOK){
        return arefnum(code, storereg);
    }
    return reg;
}

int genfun(TOKEN code) {
    TOKEN tok = code->operands;
    TOKEN lhs = tok->link;  
    int cnt = 0;
    while (lhs) {
      genarith(lhs);        
      lhs = lhs->link;
      cnt ++;
    }
    asmcall(tok->stringval);  
    SYMBOL sym = searchst(tok->stringval);
    if (sym->datatype->basicdt == REAL) {
      return XMM0;
    } else if (sym->datatype->basicdt == INTEGER) {
      return EAX;
    } else {
      return RAX;
    }
}

int funcallin(TOKEN code){
  if (code->whichval == FUNCALLOP) {
    return 1;
  } else if (code->link) {
    return funcallin(code->link);
  } else {
    return 0;
  }
}

int assignOPtable(TOKEN code) {
    TOKEN lhs = code->operands;
    TOKEN rhs = lhs->link;
    int tempREG = 0;
    int dt = code->basicdt;
    if(dt==POINTER) dt = 2;
    int op = code->whichval;
    int reg = genarith(lhs);
    if(rhs == NULL){
        tempREG = getreg(dt);
        asmfneg(reg, tempREG);
    } else {
        if(funcallin(rhs)){
            asmsttemp(reg);
            tempREG = genarith(rhs);
            reg = getreg(dt);
            asmldtemp(reg);  
        }else{
            tempREG = genarith(rhs);      
        }
        if (dt == 0) {
            asmrr(intOP[op], tempREG, reg);    
        } else if (dt == 1)
            {
            asmrr(realOP[op], tempREG, reg);    
        } else if (dt == 2 )
            {
            asmrr(pointOP[op], tempREG, reg);    
                }        
            }
        registerTable[tempREG] = 0;

    return reg;
}

/* Trivial version */
/* Generate code for arithmetic expression, return a register number */
int genarith(TOKEN code){
    int num, reg = -1;
    double thereal;
    TOKEN lhs, rhs;
    SYMBOL symbol;
    switch ( code->tokentype ){ 
        case NUMBERTOK:
            switch (code->basicdt){
                case INTEGER:
                    num = code->intval;
                    reg = getreg(INTEGER);
                    if ( num >= MINIMMEDIATE && num <= MAXIMMEDIATE )
                        asmimmed(MOVL, num, reg);
                    break;
                case REAL:
                    thereal = code->realval;
                    reg = getreg(REAL);
                    makeflit(thereal, nextlabel);
                    asmldflit(MOVSD, nextlabel, reg);
                    nextlabel++;
                    break;
                case POINTER:
                    num = code->intval;
                    reg = getreg(INTEGER);
                    asmimmed(MOVQ, num, reg);
                    break;
            }
            break;
            
        case STRINGTOK:
            registerTable[EDI] = 1;
            num = nextlabel++;
            makeblit(code->stringval, num);
            reg = EDI;
            asmlitarg(num, reg);
            break;
            
        case IDENTIFIERTOK:
            symbol = searchst(code->stringval);
            int ofs = symbol->offset - stkframesize;
            if (symbol->basicdt == INTEGER) {
                 reg = getreg(0);
                asmld(MOVL, ofs, reg, symbol->namestring);
            } else if (symbol->basicdt == REAL)
            {
                reg = getreg(REAL);
                asmld(MOVSD, ofs, reg, symbol->namestring);
            } else if (symbol->basicdt == POINTER)
            {
                reg = getreg(0);
                asmld(MOVQ, ofs, reg, symbol->namestring);
            }
            break;
            
         case OPERATOR:
            lhs = code->operands;
            rhs = lhs->link;
            int tempREG = -1;
            if(code->whichval == FUNCALLOP){
                reg = genfun(code);
            }
            else if(code->whichval == FIXOP){
                tempREG = genarith(lhs);
                reg = getreg(INTEGER);
                asmfix(tempREG, reg);
                registerTable[tempREG] = 0;
            }
            else if(code->whichval == AREFOP){
                reg = genaref(code, -1);
            }
            else if(code->whichval == POINTEROP){
                reg = genarith(lhs);
            }
            else if(code->whichval == FLOATOP){
                tempREG = genarith(lhs);
                reg = getreg(REAL);
                asmfloat(tempREG, reg);
                registerTable[tempREG] = 0;
            }
            else if(code->basicdt == INTEGER || code->basicdt == REAL || 
                    code->basicdt == POINTER){
                reg = assignOPtable(code);
             }
            
     };
    return reg;
}

/* Generate code for a Statement from an intermediate-code form */
void genc(TOKEN code)
  {  TOKEN tok, lhs, rhs;
     int reg, offs;
     SYMBOL sym;
     switch ( code->whichval )
       { case PROGNOP:
	   tok = code->operands;
	   while ( tok != NULL )
	     {  genc(tok);
		tok = tok->link;
	      };
	   break;
	 case ASSIGNOP:                   /* Trivial version: handles I := e */
	   lhs = code->operands;
	   rhs = lhs->link;
	   reg = genarith(rhs);              /* generate rhs into a register */
	   
        if(lhs->whichval == AREFOP && lhs->tokentype == OPERATOR ){
            genaref(lhs, reg);
            registerTable[reg] = 0;
        }else{
            sym = lhs->symentry;              /* assumes lhs is a simple var  */
	        offs = sym->offset - stkframesize; /* net offset of the var   */
           switch (sym->basicdt)            /* store value into lhs  */
             { case INTEGER: asmst(MOVL, reg, offs, lhs->stringval);
                 break;
              case REAL: asmst(MOVSD, reg, offs, lhs->stringval);
                 break;
              case POINTER: asmst(MOVQ, reg, offs, lhs->stringval);
                 break;
             };
             registerTable[reg] = 0;
        }
           break;
	 case FUNCALLOP:
       genfun(code);
	   break;
	 case GOTOOP:
       asmjump(JMP, code->operands->intval);
	   break;
	 case LABELOP:
       asmlabel(code->operands->intval);
	   break;
	 case IFOP:
        tok = code->operands;
        lhs = tok->operands;
        rhs = lhs->link;
        int dt = lhs->basicdt;
        reg = genarith(lhs);
        int tempREG = genarith(rhs);
        if (dt > 999) {
            SYMBOL typesym = searchst(lhs->stringval);
            dt = typesym->basicdt;
        }
        if(dt == POINTER)
          asmrr(pointOP[tok->whichval], tempREG, reg);
          else if (dt == 0)
          {
              asmrr(intOP[tok->whichval], tempREG, reg);
          }
          else if (dt == 1)
          {
              asmrr(realOP[tok->whichval], tempREG, reg);
          }
          
        registerTable[reg] = 0;
        registerTable[tempREG] = 0;

        int cur;
        cur = nextlabel++;
        asmjump(jumpOP[tok->whichval], cur);

        if(tok->link->link !=NULL){
            genc(tok->link->link);
        }
        int end = nextlabel++;
        asmjump(JMP, end);
        asmlabel(cur);
        genc(tok->link);
        asmlabel(end);
	   break;
	 };

  }