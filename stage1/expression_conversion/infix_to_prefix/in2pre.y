%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE char*
extern FILE *yyin;
%}

%token NUM PLUS MINUS MUL DIV MOD
%left PLUS MINUS
%left MUL DIV MOD

%%

start : expr '\n'		{printf("%s\n",$1);}
      ;

expr: expr PLUS expr     {$$=(char*)malloc(100*sizeof(char));
			strcpy($$,"+");
			strcat($$," ");
			strcat($$,$1);
			strcat($$," ");
			strcat($$,$3);
			}

    | expr MINUS expr      {$$=(char*)malloc(100*sizeof(char));
			strcpy($$,"-");
			strcat($$," ");
			strcat($$,$1);
			strcat($$," ");
			strcat($$,$3);
			}

    | expr MUL expr      { $$=(char*)malloc(100*sizeof(char));
			strcpy($$,"*");
			strcat($$," ");
			strcat($$,$1);
			strcat($$," ");
			strcat($$,$3);
			}

    | expr DIV expr      {$$=(char*)malloc(100*sizeof(char));
			strcpy($$,"/");
			strcat($$," ");
			strcat($$,$1);
			strcat($$," ");
			strcat($$,$3);
			}

    | expr MOD expr      {$$=(char*)malloc(100*sizeof(char));
			strcpy($$,"%");
			strcat($$," ");
			strcat($$,$1);
			strcat($$," ");
			strcat($$,$3);
			}
    | '(' expr ')'		{$$ = $2;}
    | NUM             		{$$=$1;}
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
	return 1;
}

