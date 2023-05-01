%{
	    #include<stdio.h>
	    #include<string.h>
	    #include<stdlib.h>
	    #include<ctype.h>
	    #include"lex.yy.c"
	    
	    void yyerror();
	    int yylex();
	    int yywrap();

	    int flag = 0;
%}
	
%token FLOAT_NUM ADD MULTIPLY DIVIDE SUBTRACT EXPONENT MODULO UNARY NUMBER ID EQUALTO

%%

	program: body
	;

	body: expression
	| expression EQUALTO expression
	;
			
	expression: expression arithmetic expression 
	| value
	| value UNARY
	| UNARY value
	;
	
	arithmetic: ADD 
	| SUBTRACT 
	| MULTIPLY
	| DIVIDE
	| EXPONENT
	| MODULO
	;
	
	value: NUMBER
	| FLOAT_NUM
	| ID
	;
	
	
%%
	
int main()
{
	printf("Enter Expression:\n");
	yyparse();
	if(flag == 0)	printf("Valid Expression\n");
	
}
	
void yyerror() 
{
	flag = 1;
	printf("Invalid Expression\n");
}
