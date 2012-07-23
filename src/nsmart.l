
     /*DEFINITIONS*/
D [0-9]
letter [A-Za-z]
L	[a-zA-Z_]
LL [a-z]
UL [A-Z]

%{
	#include <stdio.h>
	#include <stdlib.h>
	void yyerror(char *s);
	#include "op.h"
	#include "nsmart.tab.h"
	char *literal = NULL;
	unsigned int literal_length = 0;
	unsigned int line_num = 1;
	void comment(void);
	char * process_literal(char *yytext);
%}

%%   /*RULES*/

"/*"			{ comment(); }

"PACKAGE"	{	return PACKAGE;	}
"TYPE"		{  	return TYPE;		}
"IS"		{  	return IS;		}
"END"		{  	return END;		}
"SYMBOLIC"	{  	return SYMBOLIC;		}
"RECORD"	{  	return RECORD;		}
"RETURN"	{  	return RETURN;		}
"NODE"	{  	return NODE;		}
"IN"	{  	return IN;		}
"INTO"	{  	return INTO;		}
"OUT"	{  	return OUT;		}
"FROM"	{  	return FROM;		}
"TO"	{  	return TO;		}
"ARRAY"	{  	return ARRAY;		}
"OF"	{  	return OF;		}
"GROUP"	{  	return GROUP;		}
"NETWORK"	{  	return NETWORK;		}
"LAYER"		{ 	return LAYER;		}
"CONST"		{ return CONST; }
"VAR"		{ return VAR; }
"PROCEDURE"		{ return PROCEDURE; }
"EXTERNAL"		{ return EXTERNAL; }
"INCLUDED"		{ return INCLUDED; }
"FUNCTION"		{ return FUNCTION; }
"REDUCTION"		{ return REDUCTION; }
"NEURAL"		{ return NEURAL; }
"WTA"		{ return WTA; }
"MERGE"		{ return MERGE; }
"IOSTYLE"		{ return IOSTYLE; }
"CASE"		{ return CASE; }
"CONNECTION"		{ return CONNECTION; }
"FUNC"		{ return FUNC; }
"KINDS"		{ return KINDS; }
"IO_STYLE"		{ return IO_STYLE; }
"IOSPEC"		{ return IOSPEC; }
"STYLE"		{ return STYLE; }
"IF"		{ return IF; }
"ELSE"		{ return ELSE; }
"ELSEIF"		{ return ELSEIF; }
"THEN"		{ return THEN; }
"REPEAT"		{ return REPEAT; }
"FOR"		{ return FOR; }
"WHILE"		{ return WHILE; }
"UNTIL"		{ return UNTIL; }
"UPTO"		{ return UPTO; }
"DOWNTO"		{ return DOWNTO; }
"BREAK"		{ return BREAK; }
"REPLICATE"		{ return REPLICATE; }
"EXTEND"		{ return EXTEND ; }
"BY"		{ return BY; }
"CONNECT"		{ return CONNECT; }
"DISCONNECT"		{ return DISCONNECT; }
"OR"		{ return OR; }
"XOR"		{ return XOR; }
"AND"		{ return AND; }
"BITOR"		{ return BITOR; }
"BITXOR"		{ return BITXOR; }
"BITAND"		{ return BITAND; }
"LSHIFT"		{ return LSHIFT; }
"RSHIFT"		{ return RSHIFT; }
"MAXINDEX"		{ return MAXINDEX; }
"NOT"		{ return NOT; }
"BITNOT"		{ return BITNOT; }
"MIN"		{ return MIN; }
"MAX"		{ return MAX; }
"RANDOM"		{ return RANDOM; }
"ME"		{ return ME; }
"YOU"		{ return YOU; }
"INDEX"		{ return INDEX; }
"PRINT"		{ return PRINT;}
"SCAN"		{ return SCAN;}
"READ"		{ return READ;}
"WRITE"		{ return WRITE;}
"OPEN"		{ return OPEN;}
"CLOSE"		{ return CLOSE;}
"+="		{ return PLUS_EQUAL; }
"-="		{ return MINUS_EQUAL;}
"*="		{ return MULTIPLY_EQUAL; }
"/="		{ return DIVIDE_EQUAL; }
"%="		{ return MOD_EQUAL; }
"<--"		{ return INPUT_ASSIGNMENT; }
"-->"		{ return OUTPUT_ASSIGNMENT; }
"..."		{ return ELIPSES;}
"**"		{ return EXPONENT_OPERATOR; } 

";"	{ /*printf("\nSEMICOLON\n");*/ return (';'); }
"+"	{	return('+'); }
"-"	{	return('-'); }
"*"	{	return('*'); }
"/"	{	return('/'); }
"{"	{	return('{'); }
"}"	{	return('}'); }
"("	{	return('('); }
")"	{	return(')'); }
"["	{	return('['); }
"]"	{	return(']'); }
"."	{	return ('.'); }
","	{	return (','); }
"="	{	return ('='); }
"=="	{	return (LOGICAL_EQ); }
"<"	{	return (LOGICAL_LT); }
"<="	{	return (LOGICAL_LT_EQ); }
">"	{	return (LOGICAL_GT); }
">="	{	return (LOGICAL_GT_EQ); }
"!="	{	return (LOGICAL_NEQ); }
"||"	{	return (LOGICAL_OR); }
"&&"	{	return (LOGICAL_AND); }
"|"	{	return (INCLUSIVE_OR); }
"&"	{	return (INCLUSIVE_AND); }
"^"	{	return (LOGICAL_XOR); }


(({D}+)|(0[xX][0-9a-fA-F]*)) {
				literal = yytext;
				return INTEGER_DENOTER ;
			      }
({D}+\.{D}+)([eE][\+\-]?[0-9]+)?	{
						return REAL_DENOTER;
					}


{LL}({L}|{D})*	{	literal = yytext;
			literal_length = yyleng; 
			return lower_case_identifier; 
		}

{UL}({L}|{D})*	{	literal = yytext;
			literal_length = yyleng; 
			return upper_case_identifier; 
		}
	/*MATCH LITERAL STRINGS*/
\"(\\.|[^\\"\n])*\"	{
					/*printf("\nLITERAL %s\n");*/
					/*literal = yytext;*/
					literal = process_literal(yytext);
					return STRING_DENOTER;
				}

[ \t]+	{ /*printf("\nWHITESPACE\n");*/ /*IGNORE WHITE SPACES*/;}
[\n]	{ line_num++; }


	
	/*MATCH EVERYTHING EXCEPT NEW LINE*/
.	{ ECHO;}

%%   

/*ROUTINES*/
int yywrap (void)
{
	return 1;
}

char * process_literal(char *yytext)
{
	char *temp = NULL;
	char *literal = NULL;
	
	literal = malloc(strlen(yytext)+1);
	if(literal == NULL)
		printf("ERROR: Malloc failed : %s %d\n",__FILE__, __LINE__);
		
	temp = literal;
	while (*yytext)
	{
		if (*yytext == '\\')
		{
			yytext++;
			switch (*yytext)
			{
				case 'n' :
					*(temp++) = '\n';
					break;
				case 'b' :
					*(temp++) = '\b';
					break;
				case 't' :
					*(temp++) = '\t';
					break;
				case '\\' :
					*(temp++) = '\\';
				default:
					*(temp++) = *yytext;
					break;
			}
		} else {
			//ignore double-quotes
			if (*yytext != '\"')
			*temp++ = *yytext;
		}
		yytext++;
	}
	*(temp) = '\0';
	
	return (literal);
}

void comment(void)
{
	char c, prev = 0;
  
	while ((c = input()) != 0)      /* (EOF maps to 0) */
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	printf("\nunterminated comment\n");
}
