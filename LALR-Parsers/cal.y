%{
#include <stdio.h>
#include <math.h>
int flag = 0;
%}

%token NUMBER UnaryNeg UnaryPos;
%left '+' '-';
%left '*' '/' '%';
%left '^';
%left '(' ')';

%%
exp: E{
	printf("\n Result= %d\n", $$);
	return 0;
	}
   ;

E: E'+'E {$$=$1+$3;}
 | E'-'E {$$=$1-$3;}
 | E'*'E {$$=$1*$3;}
 | E'/'E {$$=$1/$3;}
 | E'%'E {$$=$1%$3;}
 | E'^'E {$$=pow($1, $3);}
 | E UnaryPos {$$=$1 + 1;}
 | E UnaryNeg {$$=$1 - 1;}
 | '(' E ')' {$$=$2;}
 | NUMBER {$$=$1;}
 ;

%%

void main()
{
	printf("Enter Expression: \n");
	yyparse();
	if(flag == 0)
	{
		printf("Valid Expression\n");
	}	
}

void yyerror()
{
	printf("Invalid Expression\n");
	flag = 1;
}
