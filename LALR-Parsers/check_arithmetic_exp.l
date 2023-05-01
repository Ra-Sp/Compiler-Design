%{
    #include "y.tab.h"
%}

alpha [a-zA-Z]
digit [0-9]
unary "++"|"--"

%%
[-]?{digit}+                { return NUMBER; }
[-]?{digit}+\.{digit}{1,6}  { return FLOAT_NUM; }
{unary}                     { return UNARY; }
{alpha}({alpha}|{digit})*   { return ID; }
"="                         { return EQUALTO; }
"+"                         { return ADD; }
"-"                         { return SUBTRACT; }
"/"                         { return DIVIDE; }
"*"                         { return MULTIPLY; }
"^"			    { return EXPONENT; }
"%"                         { return MODULO;}
[ \t]*                      { ; }
[\n]			    {return 0; }
%%

int yywrap() 
{
    return 1;
}
