%{
	    #include<stdio.h>
	    #include<string.h>
	    #include<stdlib.h>
	    #include<ctype.h>
	    #include"lex.yy.c"
	    
	    void yyerror(const char *s);
	    int yylex();
	    int yywrap();
%}
	
%token VOID CHARACTER PRINTF SCANF INT FLOAT CHAR FOR WHILE IF ELSE TRUE FALSE NUMBER FLOAT_NUM ID LE GE EQ NE GT LT AND OR STR ADD MULTIPLY DIVIDE SUBTRACT UNARY INCLUDE RETURN 
	
%%
	
	program: headers main '(' ')' '{' body return '}' { printf("program compiled successfully_no_of_lines %d\n",countn);}
	;
	
	headers: headers headers
	| INCLUDE
	;
	
	main: datatype ID
	;
	
	datatype: INT 
	| FLOAT 
	| CHAR
	| VOID
	;
	
	body: FOR '(' statement ';' condition ';' statement ')' '{' body '}'
	| WHILE '('statement ')' '{' body '}'
	| IF '(' condition ')' '{' body '}' else
	| statement ';' 
	| body body
	| PRINTF '(' STR ',' ID ')' ';'
                | PRINTF '(' STR ')' ';'
	| SCANF '(' STR ',' '&' ID ')' ';'
	;
	
	else: ELSE '{' body '}'
	|
	;
	
	condition: value relop value 
	| TRUE 
	| FALSE
	;
	
	statement: datatype ID init 
	| ID '=' expression 
	| ID relop expression
	| ID UNARY 
	| UNARY ID
	;
	
	init: '=' value 
	|
	;
	
	expression: expression arithmetic expression
	| value
	;
	
	arithmetic: ADD 
	| SUBTRACT 
	| MULTIPLY
	| DIVIDE
	;
	
	relop: LT
	| GT
	| LE
	| GE
	| EQ
	| NE
	;
	
	value: NUMBER
	| FLOAT_NUM
	| CHARACTER
	| ID
	;
	
	return: RETURN value ';' 
	|
	;
	
%%
	
	int main() {
	    yyparse();
	}
	
	void yyerror(const char* msg) {
	    printf("error - %s\n", msg);
	    printf("Error in line no.: %d\n",countn);
	}
