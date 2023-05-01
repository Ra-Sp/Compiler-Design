**LALR Parsers using YACC & Lex Tool**

1. Arithmetic Expression Syntax Checker:

              Lex -- check_arithmetic_exp.l

              YACC -- check_arithmetic_exp.y


2. Arithmetic Expression Evaluator (Based on Operator Precendence)

              Lex -- cal.l

              YACC -- cal.y


3. C Program Syntax Checker

              Lex -- program_syntax.l

              YACC -- program_syntax.y
              
Commands to run the above files:

          $lex <file_name.l>
          $yacc -d <file_name.y>
          $gcc y.tab.c
          $./a.out
          
          
