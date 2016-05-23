%{
	#include <stdio.h>
%}

number [0-9]+

%%
{number} {return atoi(yytext);}
%%

int yywrap()
{
	return 1;
}

main()
{

	int num;
	num=yylex();
	printf("Found: %d\n",num);
	return 0;
}
