%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern FILE *yyin;
%}

%token NUM PLUS MINUS MUL DIV MOD
%left PLUS MINUS
%left MUL DIV
%left MOD

%%

start : expr '\n'		{printf("\n");}
      ;

expr: expr PLUS expr     {printf("+ ");}

    | expr MINUS expr      {printf("- ");}

    | expr MUL expr      {printf("* ");}
    | expr DIV expr      {printf("/ ");}

    | expr MOD expr      {printf("%%");/*to print % we need to give %%*/}
    | '('expr')'
    | NUM             		{printf("%d ",$1);}
    ;

%%

yyerror(char const *s)
{
    printf("error %s\n",s);
}

main(int argc,char* argv[])
{
    if(argc==2)
    {
        yyin=fopen(argv[1],"r");
    }
    yyparse();
    return 0;
}
