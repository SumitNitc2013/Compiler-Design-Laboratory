%{
	#include <stdio.h>
	int yylval;
%}

number [0-9]+

%%
{number} {yylval=atoi(yytext);
	  if(yylval%2==0)
	     printf("Even\n");
	  else
	     printf("Odd\n");
	  exit(0);
	}

%%

int yywrap()
{
	return 1;
}

main()
{
	//for pattern matching use lexical analyzer (generated by lex)
	//for grammar checking(sytax anlysis) use parser(generated by yacc)
	yylex();
	return 0;
}
