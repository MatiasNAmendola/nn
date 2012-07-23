
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     lower_case_identifier = 258,
     upper_case_identifier = 259,
     TYPE = 260,
     IS = 261,
     END = 262,
     SYMBOLIC = 263,
     RECORD = 264,
     NODE = 265,
     IN = 266,
     OUT = 267,
     INTO = 268,
     FUNC = 269,
     CONNECTION = 270,
     LAYER = 271,
     FROM = 272,
     TO = 273,
     ARRAY = 274,
     OF = 275,
     CONST = 276,
     VAR = 277,
     PROCEDURE = 278,
     EXTERNAL = 279,
     INCLUDED = 280,
     FUNCTION = 281,
     REDUCTION = 282,
     NEURAL = 283,
     WTA = 284,
     MERGE = 285,
     RETURN = 286,
     IOSTYLE = 287,
     CASE = 288,
     GROUP = 289,
     NETWORK = 290,
     KINDS = 291,
     IO_STYLE = 292,
     IOSPEC = 293,
     STYLE = 294,
     IF = 295,
     ELSE = 296,
     ELSEIF = 297,
     THEN = 298,
     REPEAT = 299,
     FOR = 300,
     WHILE = 301,
     UNTIL = 302,
     UPTO = 303,
     DOWNTO = 304,
     BREAK = 305,
     REPLICATE = 306,
     EXTEND = 307,
     BY = 308,
     CONNECT = 309,
     DISCONNECT = 310,
     OR = 311,
     XOR = 312,
     AND = 313,
     BITOR = 314,
     BITXOR = 315,
     BITAND = 316,
     LSHIFT = 317,
     RSHIFT = 318,
     MAXINDEX = 319,
     NOT = 320,
     BITNOT = 321,
     MIN = 322,
     MAX = 323,
     RANDOM = 324,
     ME = 325,
     YOU = 326,
     INDEX = 327,
     INPUT_ASSIGNMENT = 328,
     OUTPUT_ASSIGNMENT = 329,
     LESS_THEN_GREATHER_THEN = 330,
     LESS_THEN_EQUAL = 331,
     GREATHER_THEN_EQUAL = 332,
     ELIPSES = 333,
     EXPONENT_OPERATOR = 334,
     LOGICAL_EQ = 335,
     LOGICAL_LT = 336,
     LOGICAL_LT_EQ = 337,
     LOGICAL_GT = 338,
     LOGICAL_GT_EQ = 339,
     LOGICAL_NEQ = 340,
     LOGICAL_OR = 341,
     LOGICAL_AND = 342,
     INCLUSIVE_OR = 343,
     INCLUSIVE_AND = 344,
     LOGICAL_XOR = 345,
     INTEGER_DENOTER = 346,
     REAL_DENOTER = 347,
     EQUAL = 348,
     PLUS_EQUAL = 349,
     MINUS_EQUAL = 350,
     MULTIPLY_EQUAL = 351,
     DIVIDE_EQUAL = 352,
     MOD_EQUAL = 353,
     STRING_DENOTER = 354,
     PACKAGE = 355,
     PRINT = 356,
     SCAN = 357,
     READ = 358,
     WRITE = 359,
     OPEN = 360,
     CLOSE = 361
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 31 "nsmart.y"

OP    *op;     // opcode
char  *t_sym;  // symbols
int    t_int;  // integer
unsigned int t_uint; //unsigned integer
char  *t_op;   // operator



/* Line 1676 of yacc.c  */
#line 168 "nsmart.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


