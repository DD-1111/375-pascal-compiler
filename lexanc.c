/* lex1.c         14 Feb 01; 31 May 12; 11 Jan 18       */

/* This file contains code stubs for the lexical analyzer.
   Rename this file to be lexanc.c and fill in the stubs.    */

/* Copyright (c) 2018 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "lexan.h"
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <limits.h>



/* This file will work as given with an input file consisting only
 of integers separated by blanks:
 make lex1
 lex1
 12345 123    345  357
 */

/* the lists all have " " in the first place, because 0 is used to indicate not found */
static char *delimiterList[] = { "  ", ",", ";", ":", "(", ")", "[", "]", ".." };
static char *reserveList[] = { " ", "array", "begin", "case", "const", "do",
			"downto", "else", "end", "file", "for", "function", "goto", "if",
			"label", "nil", "of", "packed", "procedure", "program", "record",
			"repeat", "set", "then", "to", "type", "until", "var", "while",
			"with" };
static char *operatorList[] = { " ", "+", "-", "*", "/", ":=", "=", "<>", "<",
			"<=", ">=", ">", "^", ".", "and", "or", "not", "div", "mod", "in" };
/* Skip blanks and whitespace.  Expand this function to skip comments too. */
/* This file will work as given with an input file consisting only
   of integers separated by blanks:
   make lex1
   lex1
   12345 123    345  357
   */

void get2char(){
	getchar();
	getchar();
}

/* Skip blanks and whitespace.  Expand this function to skip comments too. */
void skipblanks() {
	int c;
	int nc;
	while ((c = peekchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') { /*Skip blanks and whitespace.*/
			getchar();
			// {} case
        } else if (c == '{')
        {
          do {
              getchar();
          } while ((c = peekchar()) != EOF && c != '}');
          getchar();
			//（**）case
		} else if (c == '(' && (nc = peek2char() == '*')) { 
			get2char();
			c = peekchar();
			nc = peek2char();
			while (c != EOF) {
				getchar();
				// now it points to c
				if (c == '*' && nc == ')') {
					break;
				}
				c = peekchar();
				nc = peek2char();
			}
			//remember to skip the )
			getchar();
		} else {
			break;
		}
	}
}

/* check the delimiter and return the index, 0 if not found.*/
int deliCheck(char* tgt) {
	for (int i = 1; i < 9; i++) {
		if (strcmp(tgt, delimiterList[i]) == 0) return i;
	}
	return 0;
}

/* check the operator and return the index, 0 if not found.*/
int operCheck(char* tgt) {
	for (int i = 1; i < 20; i++) {
		if (strcmp(tgt, operatorList[i]) == 0) return i;
	}
	return 0;
}


/* Get identifiers and reserved words */
TOKEN identifier(TOKEN tok) {
	int c = peekchar();
	int count = 0;
	char word[16];
	// no bother
	if (c == EOF) {
		return (tok);
	}
	if (CHARCLASS[c] != ALPHA) {
		// can't be a idf/rsv/opr if the first char is a num
		return (tok);
	}
	c = getchar();
	word[count++] = c;
	// build a string
	while ((c = peekchar()) != EOF
			&& (CHARCLASS[c] == ALPHA || CHARCLASS[c] == NUMERIC)) {
		if (count < 15) {
			word[count++] = c;
		}
		c = getchar();
	}
	// end the string with 0
	word[count] = 0;
	// check for  idf/rsv/opr
	int reserIndex = 0;
	for (int i = 1; i < 30; i++) {
		if (strcmp(word, reserveList[i]) == 0) {
			reserIndex = i;
			}
		}
	int operIndex = operCheck(word);
	if (reserIndex != 0) {
		tok->whichval = reserIndex;
		tok->tokentype = RESERVED;
	} else if (operIndex != 0) {
		tok->whichval = operIndex;
		tok->tokentype = OPERATOR;
	} else {
		tok->tokentype = IDENTIFIERTOK;
		strcpy(tok->stringval, word);
	}
	return(tok);
}

TOKEN getstring(TOKEN tok) {
	int c = peekchar();
	int nc;
	int count = 0;
	char word[16];
	// no bother if it is not a '
	if (c == EOF || c != '\'') return tok;
	c = getchar();
	while ((c = peekchar()) != EOF) {
		nc = peek2char();
		if (c == '\'' && nc != '\'') {
			break;
		} else {
			c = getchar();
			if (count < 15) {
				word[count++] = c;
			}
			// should skip one while meeting two successive '
			if (c == '\'' && nc == '\'') getchar();
		}
	}
	getchar();
	word[count] = 0;
	strcpy(tok->stringval, word);
	tok->tokentype = STRINGTOK;
	return tok;
}


TOKEN special(TOKEN tok) {
	int c = peekchar();
	int nc = peek2char();
	char spe[3];
	int deliIndex = 0;
	int operIndex = 0;
	if (c == EOF) {
		return tok;
	}
	if (nc != EOF && CHARCLASS[nc] == SPECIAL) {
		spe[0] = c;
		spe[1] = nc;
		spe[2] = 0;
		// check 2-chars deli and oper
		deliIndex = deliCheck(spe);
		operIndex = operCheck(spe);
		if (deliIndex != 0 || operIndex != 0) {
			get2char();
			// no need to update index
		} else {
			getchar();
			spe[1] = 0;
		deliIndex = deliCheck(spe);
		operIndex = operCheck(spe);
		}
	} else {
		spe[0] = c;
		spe[1] = 0;
		getchar();
		// Don't know how to pass a list in C
		deliIndex = deliCheck(spe);
		operIndex = operCheck(spe);
	}
	if (deliIndex != 0) {
		tok->whichval = deliIndex;
		tok->tokentype = DELIMITER;
	} else if (operIndex != 0) {
		tok->whichval = operIndex;
		tok->tokentype = OPERATOR;
	} else {
		printf("***Token %s is not valid****\n", spe);
	}
	return tok;
}


/* Get and convert unsigned numbers of all types. */
TOKEN number (TOKEN tok)
{
	int c;
    long num = 0;
	int notInt = 0;
    double dp = 0;
	double exp = 0;
    int expSignFlag = 1;
	int charval = 0;
    //set token
    tok->tokentype = NUMBERTOK;
    //before decimal point, integer part
    while ((c = peekchar()) != EOF && CHARCLASS[c] == NUMERIC){
        c = getchar();
        charval = (c - '0');
        if(num <= INT_MAX){
            num = num * 10 + charval;
        }else{
            dp++;
        }
    }
	c = peekchar();
	// also check for two '.' case
	if (c != EOF && ((c != 'e' && c != 'E' && c != '.') | (c == '.' && peek2char() == '.'))) {
		tok->basicdt = INTEGER;
        tok->intval = num;
        num *= pow(10, dp);
        if(num > INT_MAX){
            printf("Out of range (I)\n");
            while(num>INT_MAX) {
				num /= 10;
			}
            tok->intval = num;
            return tok;
        }
        tok->intval = num;
	}

    // decimal part
    if(peekchar() == '.' && (c = peek2char()) != EOF && CHARCLASS[c] == NUMERIC){
        notInt = 1;
        getchar();
        while((c = peekchar()) != EOF && CHARCLASS[c] == NUMERIC){
            c = getchar();
            charval = (c - '0');
            if(num <= INT_MAX){
                num = num * 10 + charval;
                dp--;
            }
        }
    }

    // exponent
    if(((c = peekchar()) == 'e' || c == 'E') && peek2char() != EOF){
        notInt = 1;
        getchar(); 
        c = peekchar(); 
        if(c == '-'){
            getchar(); 
			expSignFlag = -1;
        } else if (c =='+'){
            getchar(); 
        }
        while ((c = peekchar())!= EOF && CHARCLASS[c] == NUMERIC){
            getchar();
            charval = (c - '0');
            exp = exp * 10 + charval;
        }
        exp *= expSignFlag;
		
    }
    exp += dp;	
    if(notInt | exp < 0){
        tok->basicdt = REAL;
		double value;
        value = num * pow(10, exp);
        if(value>FLT_MAX || value< FLT_MIN){
            printf("Out of range (F)\n");
            tok->realval = 0;
            return tok;
        }
        tok->realval = value;
	}
    return (tok);
}