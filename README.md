# Compiler-Design
A repo with basic compiler design resources and programs in C, Lex and Yacc


**What exactly are Compilers?**

Programming languages are notations for describing computations to people and to machines. The world as we know it depends on programming languages, because all the software running on all the computers was written in some programming language. But, before a program can be run, it first must be translated into a form in which it can be executed by a computer. 

The software systems that do this translation are called **compilers**. 

**Lex**

A tool, or in a more recent implementation **Flex**, that allows one to specify a lexical analyzer by specifying regular expressions to describe patterns for tokens. The input notation for the Lex tool is referred to as the Lex language and the tool itself is the Lex compiler. Behind the scenes, the Lex compiler transforms the input patterns into a transition diagram and generates code, in a file called lex . yy . c, that simulates this transition diagram.


**YACC**

Yacc stands for "yet another compiler-compiler," reflecting the popularity of parser generators in the early 1970s when the first version of Yacc was created by S. C. Johnson. It is an LALR Parser Generator that facilitates the construction of the front end of a compiler.

Reference: Compilers - Priciples, Techniques & Tools by Aho, Lam, Sethi and Ullman
