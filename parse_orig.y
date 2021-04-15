%{     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 25 Jul 19   */

/* Copyright (c) 2019 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */
/* 30 Jul 13 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "pprint.h"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;

%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */

%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN

%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT

%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH


%%

program    : PROGRAM IDENTIFIER LPAREN id_list RPAREN SEMICOLON lblock DOT { parseresult = makeprogram($2, $4, $7); } ;
             ;
  id_list    :  IDENTIFIER COMMA id_list { $$ = cons($1, $3); }
             |  IDENTIFIER   { $$ = cons($1, NULL); }
             ;
  varspecs   :  vargroup SEMICOLON varspecs
             |  vargroup SEMICOLON
             ;
  vargroup   :  id_list COLON type { instvars($1, $3); }
             ;
  block      :  BEGINBEGIN statement endpart   { $$ = makeprogn($1,cons($2, $3)); }  
             ;
  vblock     :  VAR varspecs block       { $$ = $3; }
             |  block
             ;
  cblock     : CONST cdef_list tblock       { $$ = $3; }
             | tblock
             ;

  sign       :  PLUS 
             |  MINUS
             ;

  constant   : sign IDENTIFIER     { $$ = unaryop($1, $2); }
             |  IDENTIFIER          { $$ = findid($1); }
             |  NUMBER
             |  STRING
             |  sign NUMBER         { $$ = unaryop($1, $2); }
             |  NIL                            { TOKEN tok = makeintc(0);
                                                 tok->basicdt = POINTER;
                                                 $$ = tok; }
             ;
  cdef       : IDENTIFIER EQ constant { instconst($1, $3); }
             ;

  cdef_list : cdef SEMICOLON cdef_list
            | cdef SEMICOLON
            ;
  tdef       :  IDENTIFIER EQ type             { insttype($1, $3); }
             ;
  tdef_list  :  tdef SEMICOLON tdef_list
             |  tdef SEMICOLON
             ;
  tblock     : TYPE tdef_list vblock       { $$ = $3; }
             | vblock
             ;

  simpletype :  IDENTIFIER                     { $$ = findtype($1); }
             |  constant DOTDOT constant       { $$ = instdotdot($1, $2, $3); }
             |  LPAREN id_list RPAREN          { $$ = instenum($2); }
             ;
  simTL      :  simpletype COMMA simTL  { $$ = cons($1, $3); }
             |  simpletype                    { $$ = cons($1, NULL); }
             ;
  type       :  simpletype		               { $$ = $1; }
              |  POINT IDENTIFIER               { $$ = instpoint($1, $2); }
             |  ARRAY LBRACKET simTL RBRACKET OF type  { $$ = instarray($3, $6); }
             |  RECORD field_list END		   { $$ = instrec($1, $2); }

             ;
  funcall    :  IDENTIFIER LPAREN exp_list RPAREN    { $$ = makefuncall($2, $1, $3); }
             ;           
  statement  :  BEGINBEGIN statement endpart   { $$ = makeprogn($1,cons($2, $3)); }
             |  IF exp THEN statement endif   { $$ = makeif($1, $2, $4, $5); }
             |  FOR assignment TO exp DO statement   { $$ = makefor(1, $1, $2, $3, $4, $5, $6); }
             |  assignment
             |  funcall
             |  label
             |  REPEAT state_list UNTIL exp       { $$ = makerepeat($1, $2, $3, $4); }
             |  WHILE exp DO statement		   { $$ = makewhile($1, $2, $3, $4); }
             |  GOTO NUMBER					   { $$ = dogoto($1, $2); }
             ;
  state_list : statement SEMICOLON state_list  { $$ = cons($1, $3); }
             |  statement                      { $$ = cons($1, NULL); }
             ;
  exp_list  :  exp COMMA exp_list           { $$ = cons($1, $3); }
             |  exp
             ;
  endpart    :  SEMICOLON statement endpart    { $$ = cons($2, $3); }
             |  END                            { $$ = NULL; }
             ;
  endif      :  ELSE statement                 { $$ = $2; }
             |                                 { $$ = NULL; }
             ;
  assignment :  variable ASSIGN exp         { $$ = binop($2, $1, $3); }
             ;
  plus_op    :  PLUS 
             |  MINUS  
             |  OR
             ;
  compare_op :  EQ 
             |  LT 
             |  LE 
             |  GE 
             |  IN
             |  GT 
             |  NE 
             ;
  inner_exp :  inner_exp plus_op term                 { $$ = binop($2, $1, $3); }
          |  sign term                             { $$ = unaryop($1, $2); }
          |  term
             ;
  exp       :  exp compare_op inner_exp                 { $$ = binop($2, $1, $3); }
             |  inner_exp
             ;
  times_op   :  TIMES
  	  	  	 |  DIVIDE
			       |  DIV
			       |  MOD
			       |  AND
			       ;
  term       :  term times_op factor              { $$ = binop($2, $1, $3); }
             |  factor
             ;

  variable   :  IDENTIFIER                     { $$ = findid($1); }
             |  variable LBRACKET exp_list RBRACKET  { $$ = arrayref($1, $2, $3, $4); }
             |  variable POINT				   { $$ = dopoint($1, $2); }
             |  variable DOT IDENTIFIER		   { $$ = reducedot($1, $2, $3); }
             ;
  fields     :  id_list COLON type             { $$ = instfields($1, $3); }
             ;
  field_list :  fields SEMICOLON field_list    { $$ = nconc($1, $3); }
             |  fields
             ;   
 label      :  NUMBER COLON statement         { $$ = dolabel($1, $2, $3); }
             ;
  num_list    :  NUMBER COMMA num_list           { instlabel($1); }
             |  NUMBER                         { instlabel($1); }
             ;
   lblock    :  LABEL num_list SEMICOLON cblock { $$ = $4; }
             |  cblock
             ;
  factor     :  LPAREN exp RPAREN             { $$ = $2; }
             |  funcall
             |  variable
             |  NOT factor                     { $$ = unaryop($1, $2); }
             |  constant
             ;


%%

/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG        255             /* set bits here for debugging, 0 = off  */
#define DB_CONS       1             /* bit to trace cons */
#define DB_BINOP      2             /* bit to trace binop */
#define DB_MAKEIF     4             /* bit to trace makeif */
#define DB_MAKEPROGN  8             /* bit to trace makeprogn */
#define DB_PARSERES  16             /* bit to trace parseresult */
#define DB_PRGM  32          
#define DB_MAKEFC  64  
#define DB_MAKEFOR  128 
#define DB_MAKEF  3
#define DB_INSTARR  5
#define DB_INSTREC  7
#define DB_MAKEREF  9


 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int labelArray[128];
   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */

    op->basicdt = lhs->basicdt == 9999 ? rhs->basicdt : lhs->basicdt;

    if (lhs->basicdt == REAL && rhs->basicdt == REAL) {
      op->basicdt = REAL;     
    } else if (lhs->basicdt == REAL && rhs->basicdt == INTEGER) {
      op->basicdt = REAL;
      cons(lhs,  makefloat(rhs));
    } else if (lhs->basicdt == INTEGER && rhs->basicdt == REAL) {
      if (op->whichval == ASSIGNOP) {
        op->basicdt = INTEGER;
        TOKEN fixtok = makefix(rhs);
        cons(lhs, fixtok);
      } else {
        op->basicdt = REAL;
        cons(makefloat(lhs), rhs);
      }
    } 
   return op;
  }


TOKEN findid(TOKEN tok) {    
    SYMBOL sym = searchst(tok->stringval);
    tok->symentry = sym;
    if (sym->kind == CONSTSYM) {
      if (sym->basicdt == REAL || sym->basicdt == INTEGER) {
        tok->tokentype = NUMBERTOK;
        tok->basicdt = sym->basicdt;
        if (sym->basicdt == REAL) {
          tok->realval = sym->constval.realnum;
        } else {
          tok->intval = sym->constval.intnum;
        }
      }
    } else {
      SYMBOL symtp = sym->datatype;
      tok->symtype = symtp;
      if ( symtp->kind == POINTERSYM || symtp->kind == BASICTYPE) {
         tok->basicdt = symtp->basicdt;
      }
    }
    return tok;
  }


TOKEN makefix(TOKEN tok) {
  if(tok->tokentype == NUMBERTOK) {
    tok->intval = (int) tok->realval;
    tok->basicdt = INTEGER;
    return tok;
  } 
  TOKEN fixtok = makeop(FIXOP);
  fixtok->operands = tok;
  return fixtok;
}


TOKEN makefloat(TOKEN tok) {
  if(tok->tokentype == NUMBERTOK) {
    tok->realval = (double) tok->intval;
    tok->basicdt = REAL;
    return tok;
  }
  TOKEN flotok = makeop(FLOATOP);
  flotok->operands = tok;
  return flotok;
}


TOKEN unaryop(TOKEN op, TOKEN lhs) {
  op->operands = lhs;
  lhs->link = NULL;
  return op;  
}

TOKEN findtype(TOKEN tok) {
	SYMBOL sym = searchst(tok->stringval);
	tok->symentry = sym;	
	tok->symtype = sym;
	return tok;
}

/* similar idea to mkae for */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokbody, TOKEN exp) {

   TOKEN label = makelabel();
   tok = makeprogn(tok, label);
   TOKEN body = tokbody;
   body = makeprogn(body, statements);
   cons(label,body);

   int cur = labelnumber - 1;
   TOKEN newtok = makeprogn((TOKEN) talloc(), NULL);
   TOKEN gototok = makegoto(cur);
   cons(newtok, gototok);
   TOKEN bool = talloc();
   bool = makeif(bool, exp, newtok, gototok);
   cons(body, bool);
   if (DEBUG) {
         printf("makerepeat\n");
         dbugprinttok(tok);
   }
   return tok;  
}


TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  
    tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }

TOKEN maketok(int type, int val, TOKEN op){
    TOKEN tok = talloc();
    tok->tokentype = type;
    tok->whichval = val;
    tok->operands = op;
    return tok;
}


TOKEN makeintc(int num) {
	TOKEN tok = talloc();
	tok->tokentype = NUMBERTOK;
	tok->intval = num;
	tok->basicdt = INTEGER;
	return tok;
}


TOKEN checknew(TOKEN tok, TOKEN fn, TOKEN args) {
        TOKEN function = maketok(OPERATOR, FUNCALLOP, fn);
        SYMBOL typesym = args->symtype->datatype;
        tok = makeop(ASSIGNOP);
        tok->operands = args;
        args->link = function;
        while(typesym->kind == POINTERSYM){
            typesym = typesym->datatype;
        }
        fn->link = makeintc(typesym->size);
        return tok;
}

TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args)
{   
    if (strcmp(fn->stringval, "new") == 0) {
        return checknew(tok, fn, args);
    }
    if((strcmp(fn->stringval, "write") == 0) || (strcmp(fn->stringval, "writeln") == 0)){
        if (args->basicdt == INTEGER) {
            if(strcmp(fn->stringval, "write") == 0) {
                strcpy(fn->stringval, "writei");
            } else if (strcmp(fn->stringval, "writeln") == 0) {
                strcpy(fn->stringval, "writelni");
            }
        } else if (args->basicdt == REAL) {
            if(strcmp(fn->stringval, "write") == 0) {
                strcpy(fn->stringval, "writef");
            } else if (strcmp(fn->stringval, "writeln") == 0) {
                strcpy(fn->stringval, "writelnf");
            }
        }
    }
    tok->tokentype = OPERATOR;
    tok->whichval = FUNCALLOP;
    tok->operands = fn;
    fn->link = args;
    tok->basicdt = args->basicdt;

    if(!strcmp(fn->stringval, "iround"))
        tok->basicdt = INTEGER;

    return tok;
}


TOKEN makeop(int opnum) {
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = opnum;
  return tok;
}

TOKEN makelabel() {
	TOKEN label_tok = makeop(LABELOP);
	TOKEN lablenum = makeintc(labelnumber++);	
	label_tok->operands = lablenum;
	return label_tok;
}

TOKEN makegoto(int label) {
	TOKEN goto_tok = makeop(GOTOOP);
	TOKEN lablenum = makeintc(label);
	goto_tok->operands = lablenum;	
	return goto_tok;
}

TOKEN copytok(TOKEN target) {
  TOKEN copy = talloc();
  copy->basicdt = target->basicdt;
	copy->tokentype = target->tokentype;
	copy->symtype = target->symtype;
	copy->symentry = target->symentry;
  copy->whichval = target->whichval;
  copy->intval = target->intval;
  copy->realval = target->realval;
  copy->operands = target->operands;
	copy->link = target->link;
  return copy;
}

void insttype(TOKEN typen, TOKEN typetok){
    SYMBOL sym;
    SYMBOL typesym = typetok->symtype;
    sym = searchins(typen->stringval);
    sym->kind = TYPESYM;
    sym->datatype = typesym;
    sym->basicdt = typesym->basicdt;
    sym->size = typesym->size;
}

TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexp,
              TOKEN tokc, TOKEN statement) {
  TOKEN stop_tok = makeop(LEOP);
	TOKEN iterate_tok = makeop(PLUSOP);
	if (sign == -1) { 
		stop_tok ->whichval = GEOP;
		iterate_tok -> whichval = MINUSOP;
	}

  TOKEN first_i = copytok(asg->operands);
	TOKEN second_i = copytok(first_i);
	TOKEN third_i = copytok(first_i);
	stop_tok = binop(stop_tok, first_i, endexp);
  tokb->tokentype = NUMBERTOK;
  tokb->intval = 1;
  tokb->basicdt = INTEGER;
	binop(iterate_tok, second_i, tokb);
  TOKEN tok_var_incr = makeop(ASSIGNOP);
	binop(tok_var_incr, third_i, iterate_tok); 

  TOKEN goto_tok = makegoto(labelnumber); 
	cons(statement, cons(tok_var_incr, goto_tok)); 
	makeprogn(tokc, statement);
	tok = makeif(tok, stop_tok, tokc, 0);
  TOKEN label_tok = makelabel();
	cons(label_tok, tok);
	cons(asg, label_tok);  
  TOKEN out = makeprogn(talloc(), asg);
   if (DEBUG & DB_MAKEFOR){ 
     printf("makefor\n");
      dbugprinttok(out);
    };
	return out;
}


TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
	TOKEN tok_program = makeop(PROGRAMOP);
  TOKEN tok = makeprogn(talloc(), args);
	tok_program->operands = name;
  tok_program->tokentype = OPERATOR;
	name->link = tok;
	tok->link = statements;
  if (DEBUG & DB_PRGM) {
    printf("make prgm\n");
      dbugprinttok(tok_program);
  }
	return tok_program;
}

/* install variables in symbol table from the handout*/
void instvars(TOKEN idlist, TOKEN typetok)
{
    SYMBOL sym, typesym;
    int align;
    typesym = typetok->symtype;
    while(typesym && typesym->kind == TYPESYM){
        typesym = typesym->datatype;
    }
    align = alignsize(typesym);
    while ( idlist != NULL ) /* for each id */
    {
        sym = insertsym(idlist->stringval);
        sym->kind = VARSYM;
        sym->offset = /* "next" */
            wordaddress(blockoffs[blocknumber], align);
        sym->size = typesym->size;
        blockoffs[blocknumber] = /* "next" */
            sym->offset + sym->size;
        sym->datatype = typesym;
        sym->basicdt = typesym->basicdt;
        //idlist->basicdt = typesym->basicdt;
        idlist = idlist->link;
    };
}


void  instconst(TOKEN idtoken, TOKEN constok) {
  SYMBOL sym;
  sym = insertsym (idtoken->stringval);
  if (constok->basicdt == REAL) {
     sym->constval.realnum = constok->realval;
     sym-> basicdt = REAL;
  }
  if (constok->basicdt == INTEGER) {
     sym->constval.intnum = constok->intval;
     sym-> basicdt = INTEGER;
  }
  sym-> kind = CONSTSYM;
}


void  instlabel (TOKEN num){
    labelArray[labelnumber] = num->intval;
    labelnumber++;
}


TOKEN instfields(TOKEN idlist, TOKEN typetok){
    int flag = 0;
    TOKEN tok = idlist;
    SYMBOL sym = typetok->symtype;
    while(flag == 0){
        if (tok != NULL) {
          tok->symtype = sym;
          if(sym->kind != TYPESYM){
            tok->basicdt = sym->basicdt;
          }
          tok = tok->link;
        } else {
          flag = 1;
        }
    }
    if (DB_MAKEF) {
        printf("instfields\n");
        dbugprinttok(tok);
    }
    return idlist;
}


TOKEN nconc(TOKEN firstL, TOKEN secondL){
    TOKEN tok = firstL;
    while(tok->link){
        tok = tok->link;
    }
    tok->link = secondL;
    return tok;
}

TOKEN instenum(TOKEN idlist){
    TOKEN tok = idlist;
    int size = 0;
    while(tok != NULL){
        TOKEN intTok = makeintc(size);
        instconst(tok, intTok);
        tok = tok->link;
        size++;
    }
    SYMBOL sym = symalloc();
    sym->kind = SUBRANGE;
    sym->basicdt = INTEGER;
    sym->size = sizeof(int);
    sym->lowbound = 0;
    sym->highbound = size - 1;
    idlist -> symtype = sym;

    if (DEBUG) {
        printf("instenum\n");
        dbugprinttok(idlist);
    }
    return idlist;
}



TOKEN instpoint(TOKEN tok, TOKEN typename){
    SYMBOL sym = symalloc();
    sym->basicdt = POINTER;
    sym->kind = POINTERSYM;
	  sym->size = basicsizes[POINTER];
    sym->datatype = searchins(typename->stringval);;
    tok->symtype = sym;
    return tok;
}


int findlabindex (int labelnum){
    for(int i=0; i<labelnumber; i++){
        if(labelArray[i] == labelnum)
            return i;
    }
    return -1;
}


TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement){
    int labIndex = findlabindex(labeltok->intval);
    if(labIndex >= 0){
        TOKEN numtok = makeintc(labIndex);
        labeltok = maketok(OPERATOR, LABELOP, numtok);
        labeltok->link = statement;
        return maketok(OPERATOR, PROGNOP, labeltok);
    }
    return NULL;
}

TOKEN dogoto(TOKEN tok, TOKEN labeltok){
    int labIndex = findlabindex(labeltok->intval);
    return makegoto(labIndex);
}


TOKEN instrec(TOKEN rectok, TOKEN argstok){
    int curoffset = 0;
    SYMBOL sym = symalloc();
    sym->kind = RECORDSYM;
    rectok->symtype = sym;
    TOKEN args = argstok;
    TOKEN prevArg = NULL;
    int size = 0;
    SYMBOL newsym;
    while(args != NULL){
	      size = args->symtype->size;
        newsym = makesym(args->stringval);
        newsym->offset = wordaddress(curoffset, size);
        newsym->datatype = args->symtype;
        newsym->size = size;
        args->symtype = newsym;       
        if(!prevArg){
            sym->datatype = newsym;
        }else{
            prevArg->symtype->link = newsym;
        }
        curoffset = newsym->offset + size;
        prevArg = args;
        args = args->link;
    }
    sym->size = wordaddress(curoffset, 16);
    if (DB_INSTREC) {
        printf("instrec\n");
        dbugprinttok(rectok);
        printsymbol(sym);
    }
    return rectok;
}

TOKEN instdotdot(TOKEN low, TOKEN dottok, TOKEN high){
    SYMBOL sym = symalloc();
    sym->basicdt = INTEGER;
    sym->kind = SUBRANGE;
    sym->lowbound = low->intval;
    sym->highbound = high->intval;
    sym->size = sizeof(int);
    dottok->symtype = sym;
    return dottok;
}


int arraySizeHelper(SYMBOL sym, SYMBOL type){
    SYMBOL symdt = sym->datatype;
    if(symdt == type && symdt->datatype != type){
        return sym->size;
    }
    sym->size =((sym->highbound)-(sym->lowbound)+1)*arraySizeHelper(symdt, type);
    return sym->size;
}


TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
    int found = 0;
    SYMBOL recsym = var->symtype;
    if(recsym->kind == POINTERSYM) {
        recsym = recsym->datatype;
        while(recsym->kind == TYPESYM) {
            recsym = recsym->datatype;
        }
        found = 1;
    }

    SYMBOL temp = recsym;
    if(temp->kind == RECORDSYM){
        temp = recsym->datatype;
    }
    int curoffset = 0;

    while(temp) {
        if(strcmp(temp->namestring, field->stringval) == 0){
            curoffset = temp->offset;
            break;
        }
        temp = temp->link;
    }
  
    if(found==0 && var->whichval==AREFOP  && var->tokentype==OPERATOR 
            && var->operands->link->tokentype==NUMBERTOK){
        dot = var;
        dot->operands->link = makeintc(curoffset+var->operands->link->intval);
        dot->basicdt = temp->datatype->basicdt;
	      return dot;
    }

    if (var->tokentype==OPERATOR && var->whichval==AREFOP){
          int offset = makeintc(curoffset)->intval;
          var->operands->link->operands->intval += offset;
          dot = var;
    } else {
          dot = makeop(AREFOP);
          dot->operands = var;
          var->link =  makeintc(curoffset);
    }
  
    temp = temp->datatype;
    while(temp->kind == TYPESYM) {
        temp = temp->datatype;
    }

    dot->basicdt = temp->basicdt;
    dot->symtype = temp->datatype;

    return dot;
}


TOKEN instarray(TOKEN bounds, TOKEN typetok){ 
    TOKEN tok = bounds;
    TOKEN nexttok = tok->link;
    SYMBOL preArray = NULL;
    SYMBOL range = tok->symtype;
    while(tok != NULL){
        SYMBOL arraySym = symalloc();
        arraySym->kind = ARRAYSYM;
	      SYMBOL range = tok->symtype;
        while(range->kind == TYPESYM){
            range = range->datatype;
        }
	      arraySym->lowbound = range->lowbound;
        arraySym->highbound = range->highbound;
        if(nexttok == NULL){
          arraySym->datatype = searchst(typetok->stringval);
	        arraySym->size = ((arraySym->highbound)-(arraySym->lowbound)+1)*(searchst(typetok->stringval)->size);
	      }
	      if(!preArray){
	        typetok->symtype = arraySym;
	      }else{
          preArray->datatype = arraySym;
	      }
        preArray = arraySym;
        tok = tok->link;
	      if(nexttok) 
          nexttok = nexttok->link;
    }
    arraySizeHelper(typetok->symtype, searchst(typetok->stringval));
    if (DB_INSTARR) {
        printf("instarry\n");
        dbugprinttok(typetok);
	      printsymbol(typetok->symtype);
    }
    return typetok;
}


TOKEN arrayref(TOKEN arrayTok, TOKEN tok, TOKEN subs, TOKEN uselessTok) {
    TOKEN offsetTok = NULL;
    TOKEN temp = subs;
    SYMBOL arraySymbol = arrayTok->symtype;
    while(temp != NULL) {
        int size = arraySymbol->datatype->size;
        TOKEN timed;
        TOKEN next = temp->link;
        TOKEN added;
        if(temp->tokentype != NUMBERTOK) {
            timed = binop(makeop(TIMESOP), makeintc(size), temp);
        }else{
            timed = makeintc((temp->intval) * size);
        }
        int newsize = -size * arraySymbol->lowbound;
        if(timed->tokentype == NUMBERTOK){
            added = makeintc(newsize+(timed->intval));
        }else{
            added = binop(makeop(PLUSOP), makeintc(newsize), timed);
        }
        if(offsetTok) {
            if(added->tokentype == NUMBERTOK){
                offsetTok->operands->intval += added->intval;
            }else{
                offsetTok = binop(makeop(PLUSOP), offsetTok, added);
            }
        } else {
            offsetTok = added;
        }
        temp = next;
        arraySymbol = arraySymbol->datatype;
    }
    while(arraySymbol->kind == TYPESYM){
        arraySymbol = arraySymbol->datatype;
    }
    tok = maketok(OPERATOR, AREFOP, arrayTok);
    tok->basicdt = 0;
    tok->operands->link = offsetTok;
    tok->symtype = arraySymbol;
    return tok;
}




TOKEN dopoint(TOKEN var, TOKEN tok){
    SYMBOL sym = var->symtype;
    while(sym->kind == TYPESYM)
        sym = sym->datatype;
    tok = maketok(OPERATOR, POINTEROP, var);
    tok->symtype = sym;
    return tok;
}


TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement){
    TOKEN label_tok = makelabel();
    TOKEN if_token = talloc();
    if_token = makeif(if_token, expr, statement, NULL);
    tok = makeprogn(tok, label_tok);
    label_tok->link = if_token;
    TOKEN statement_tok = statement->operands;
    while(statement_tok->link != NULL) {
        statement_tok = statement_tok->link;
    }
    statement_tok->link = makegoto(label_tok->operands->intval);
    return tok;
}

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

int main(void)          /*  */
  { int res;
    initsyms();
    res = yyparse();
    printst();       /* to shorten, change to:  printstlevel(1);  */
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
    /* uncomment following to call code generator. */
   //gencode(parseresult, blockoffs[blocknumber], labelnumber);
 
  }