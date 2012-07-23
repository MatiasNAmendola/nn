 /* nsmart.y
 *
 * Copyright (c) 2011 Suhel Momin
 *
 * You may distribute under the terms of the GNU General Public License
 * 
 */

/*
 * This file holds the grammer for the nsmart language
 * The grammer is still under construction
 */

%{
	#include <stdio.h>
	#include "op.h"
	//#include "symboltable.h"
	// Adding this to avoid microsoft error for alloca
//	#ifdef _MSC_VER
//		#define alloca( x ) malloc( x )
//	#endif
	int yylex(void);
	void yyerror(char *);
	extern FILE *yyin;
	extern char *yytext;
	extern char *literal;
	extern unsigned int literal_length;

%}

%union {
OP    *op;     // opcode
char  *t_sym;  // symbols
int    t_int;  // integer
unsigned int t_uint; //unsigned integer
char  *t_op;   // operator
}

%token <t_sym>  lower_case_identifier upper_case_identifier 
%token <t_op>   TYPE IS END SYMBOLIC RECORD NODE IN OUT INTO FUNC CONNECTION LAYER  FROM TO ARRAY OF 
%token <t_op>   CONST VAR PROCEDURE EXTERNAL INCLUDED FUNCTION REDUCTION NEURAL WTA MERGE RETURN
%token <t_op>   IOSTYLE CASE GROUP NETWORK KINDS IO_STYLE IOSPEC STYLE IF ELSE
%token 		ELSEIF THEN REPEAT FOR WHILE UNTIL UPTO DOWNTO BREAK REPLICATE EXTEND BY CONNECT DISCONNECT 
%token <t_op>   OR XOR AND BITOR BITXOR BITAND LSHIFT RSHIFT MAXINDEX NOT  BITNOT
%token 		MIN	MAX	RANDOM ME YOU INDEX	
%token <t_op>   INPUT_ASSIGNMENT OUTPUT_ASSIGNMENT 
%token <t_op>   LESS_THEN_GREATHER_THEN LESS_THEN_EQUAL GREATHER_THEN_EQUAL ELIPSES EXPONENT_OPERATOR 
%token <t_op>   LOGICAL_EQ LOGICAL_LT LOGICAL_LT_EQ LOGICAL_GT LOGICAL_GT_EQ LOGICAL_NEQ LOGICAL_OR LOGICAL_AND INCLUSIVE_OR INCLUSIVE_AND LOGICAL_XOR  
%token <t_int>  INTEGER_DENOTER REAL_DENOTER
%token <t_uint> EQUAL PLUS_EQUAL MINUS_EQUAL MULTIPLY_EQUAL DIVIDE_EQUAL MOD_EQUAL  
%token 		STRING_DENOTER PACKAGE PRINT SCAN READ WRITE OPEN CLOSE

%type <op> root nsmart_program nsmart_package package_name statement_list  
%type <op> nsmart_procedure simple_procedure connection_procedure node_procedure layer_procedure network_procedure
%type <op> conn_parameter node_parameter layer_parameter network_parameter
%type <op> statement expression_statement return_statement argument_expression_list selection itiration compound_statement assignment_expression expression array_exp array_exp_list
%type <op> number  e1 e2 e3 e4 e5 e6 e7 e8 e9 e10 e11 e12 e13 e14 e15 e16 e17 e18 e19 
%type <op> literal_string 
%type <op> object_parameter object_category const_proc_object object object_name 
%type <t_uint> assign_operator 

%left	'+'	'-'
%left	'*'	'/'
%left   '|' 	'&' 	'^' 
%left 	'=' 	'!'   
%start root

%%
root: nsmart_program {$$ = create_root_op($1);} 
	;

nsmart_program: nsmart_package	{$$ = $1;}
		| statement_list	{ $$ = $1; }
		| nsmart_program nsmart_package {$$ = create_program_op($1, $2);}
		;

nsmart_package:
		PACKAGE package_name '{' statement_list '}' {$$ = create_package_op($2,$4);} 
		;
		
package_name:
	lower_case_identifier 
		{ 
			CONST_VAL	value;
			value.type = SYM_TYPE_STRING;
			value.u.s_val = create_const_str_value(literal);	
			$$ = create_const_op(value);
		}

	;
	
 
nsmart_procedure:
	simple_procedure	{$$ = $1;} 
	| connection_procedure	{$$ = $1;}
	| node_procedure	{$$ = $1;}
	| layer_procedure	{$$ = $1;}
	| network_procedure	{$$ = $1;}
	;

simple_procedure:
	FUNC object '(' object_parameter ')' '{' statement_list '}'	{$$ = create_simple_proc($2,$4,$7);}
	;

connection_procedure:
	CONNECTION  object '(' conn_parameter ')' '{' statement_list '}' {$$ = create_conn_proc($2,$4,$7);}
	;

conn_parameter:
	object object ',' object object		{$$ = create_conn_param($1,$2,$4,$5);}
	;

node_procedure:
	NODE object '(' node_parameter ')' '{' statement_list '}' {$$ = create_node_proc($2,$4,$7);}
	;

node_parameter:
	object object ',' object object		{ $$ = create_node_param($1,$2,$4,$5);}
	;

layer_procedure:
	LAYER object '(' layer_parameter ')' '{' statement_list '}'  {$$ = create_layer_proc($2, $4, $7);}
	;

layer_parameter:
	object		{ $$ = create_layer_param($1);}
	;

network_procedure:
	NETWORK object '(' network_parameter ')' '{' statement_list '}' {$$ = create_network_proc($2,$4,$7);}
	;

network_parameter:
	object object				{ $$ = create_network_param($1,$2);}
	| network_parameter ',' object object	{ $$ = create_network_param_list($1,$3,$4);}
	;

compound_statement:
	'{' statement_list '}'	{$$ = $2;}
	;

statement_list:
	statement 	{$$ = $1;} 
	| statement_list statement 	{$$ = create_statement_list_op($1,$2);} 
	;

statement:
	PRINT lower_case_identifier {$$ = create_op();}//{ print_statement(literal);} 
	| expression_statement		{ $$ = $1;}	
	| selection			{ $$ = $1;}
	| itiration			{ $$ = $1;}
	| compound_statement		{ $$ = $1;}
	| nsmart_procedure		{ $$ = $1;}
	| return_statement		{ $$ = $1;}
	;

expression_statement:
	expression ';'	{ $$ = $1;}
	;

expression:
	assignment_expression			{ $$ = $1;}
	| expression ',' assignment_expression	{ $$ = create_expression_op($1,$3);}
	;

assignment_expression:
	object_category assign_operator e2 {$$ = create_assign_op($1,$2,$3);}
	| e2	{$$ = $1;}
	;

assign_operator:
	'='		{ $$ = EQUAL_TO;}
	| PLUS_EQUAL	{ $$ = PLUS_EQUAL_TO;}
	| MINUS_EQUAL 	{ $$ = MINUS_EQUAL_TO;}
	| MULTIPLY_EQUAL { $$ = MULTIPLY_EQUAL_TO;}
	| DIVIDE_EQUAL	{ $$ = DIVIDE_EQUAL_TO; } 
	| MOD_EQUAL	{ $$ = MOD_EQUAL_TO;}
	;

selection:
	IF '(' expression ')' statement			 {$$ = create_if_op($3,$5);}
	| IF '(' expression ')' statement ELSE statement {$$ = create_if_else_op($3,$5,$7);}
	;

itiration:
	WHILE '(' expression ')' statement	{$$ = create_while_op($3,$5);}
	;

return_statement:
	RETURN	';'						{$$ = create_return_stmt_op(NULL);}
	| RETURN '(' expression ')'	';'	{$$ = create_return_stmt_op($3);}
	;
	
//e0:
//	 object	{ $$ = $1;}
//	;

e1:
	'(' expression ')'	{$$ = $2;}
	| number		{$$ = $1;}
	| literal_string {$$ = $1;}
	;

e2: // Additive
	e3	{$$ = $1;}
	| e2 '+' e3	{$$ = create_add_op($1,$3);}
	;

e3: // Subtractive
	e4 	{$$ = $1;}
	|  e3 '-' e4 {$$ = create_sub_op($1,$3);}
	;

e4: // multiplicative
	e5	{$$ = $1;}
	| e4 '*' e5 {$$ = create_mult_op($1,$3);}
	;

e5: // Division
	e6	{ $$ = $1;}
	|e5 '/' e6 {$$ = create_div_op($1,$3);}
	;

e6: // logical OR
	e7		{$$ = $1;}
	| e6 LOGICAL_OR e7	{ $$ = create_logical_or_op($1,$3);}
	;

e7: // logical AND
	e8		{ $$ = $1;}
	| e7 LOGICAL_AND e8	{ $$ = create_logical_and_op($1,$3);}
	;

e8: // inclusive OR and inclusive AND
	e9		{ $$ = $1;}
	| e8 INCLUSIVE_OR e9	{ $$ = create_inclusive_or_op($1,$3);}
	;

e9: // inclusive AND
	e10		{ $$ = $1;}
	| e9 INCLUSIVE_AND e10	{ $$ = create_inclusive_and_op($1,$3);}
	;

e10: // exclusive or
	e11
	| e10 LOGICAL_XOR e11	{ $$ = create_exclusive_or_op($1,$3);}
	;

e11: // less then , greater then, less-then-or-equal-to, greather-then-or-equal-to
	e12		{ $$ = $1;}
	| e11 LOGICAL_LT e12	{ $$ = create_lt_op($1,$3);}
	;

e12: // greater then
	e13		{ $$ = $1;}
	| e12 LOGICAL_GT e13	{ $$ = create_gt_op($1,$3);}
	;

e13: // less-than-or-equal-to
	e14		{ $$ = $1;}
	| e13 LOGICAL_LT_EQ e14	{ $$ = create_lt_eq_op($1,$3);}
	;

e14:	// greater-than-or-equal-to
	e15		{ $$ = $1;}
	| e14 LOGICAL_GT_EQ e15	{ $$ = create_gt_eq_op($1,$3);}
	;

e15: // equality 
	e16		{ $$ = $1;}
	| e15 LOGICAL_EQ e16	{ $$ = create_eq_op($1,$3);}
	;

e16: // not equal to
	e17		{ $$ = $1;}
	| e16 LOGICAL_NEQ e17	{ $$ = create_neq_op($1,$3);}
	;
 
e17: // call
	e18						{ $$ = $1;}
	| object  '(' argument_expression_list ')' 	{$$ = create_proc_call($1,$3);}
	| const_proc_object '(' argument_expression_list ')' {$$ = create_const_proc_call($1,$3);}
	;

e18:
	e19			{$$ = $1;}
	| object_category 	{$$ = $1;}
	;

e19:
	e1	{ $$ = $1;}
	;
	
//	e20					{$$ = $1;}
//	|return_statement	{$$ = $1;}
//	;

//e20:	
//	e1	{ $$ = $1;}
//	;

array_exp_list:
	array_exp			{$$ = $1;}
	| array_exp_list array_exp	{$$ = create_array_exp_list_op($1,$2);}
	;

array_exp:
	'[' expression ']'	{ $$ = create_array_exp_op($2);}
	;

argument_expression_list:
	assignment_expression					{$$ = $1;}
	| argument_expression_list ',' assignment_expression	{$$ = create_param_expression_list($1,$3);}
	;


number:
	INTEGER_DENOTER	{ 
				CONST_VAL	value;
				value.type = SYM_TYPE_INT;
				value.u.i_val =   atoi(literal); 
				$$ = create_const_op(value);
			}
	;

literal_string:
	STRING_DENOTER	{
			CONST_VAL value;
			value.type = SYM_TYPE_STRING;
			value.u.s_val = create_const_str_value(literal);
			$$ = create_const_op(value);
		}
		
object_parameter:
	object_category				{$$ = $1;}
	| object_parameter ',' object_category	{$$ = create_proc_param($1,$3);}
	;

object_category:
	object				{$$ = $1;}
	| object array_exp_list		{$$ = create_obj_array($1,$2);}
	| INCLUSIVE_AND object		{$$ = update_as_ref_const_op($2);}
	;

const_proc_object:
	PRINT			{ $$ = create_const_object_print_op();}
	| SCAN			{ $$ = create_const_object_scan_op();}
	| READ			{ $$ = create_const_object_read_op();}
	| WRITE			{ $$ = create_const_object_write_op();}
	| OPEN			{ $$ = create_const_object_open_op();}
	| CLOSE			{ $$ = create_const_object_close_op();}
	;
object:
	object_name	{ $$ = $1;}
	//| INCLUSIVE_AND object_name {$$ = update_as_ref_const_op($2);} // to support foo_bar = &foo
	;

object_name:
	lower_case_identifier	
		{ 
			CONST_VAL	value;
			value.type = SYM_TYPE_SYMBOL;
			value.u.s_val = create_const_str_value(literal);	
			$$ = create_const_op(value);
		}
	;
	

%%
extern unsigned int line_num;
void yyerror(char *s)
{
	fprintf(stderr, "WHAT IS WRONG %s at line number %d\n", s, line_num);
}


	
