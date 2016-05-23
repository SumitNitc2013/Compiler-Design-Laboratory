%{
	#include <stdio.h>
%}

number [0-9]+

%%

{number} {printf("Found: %d\n",atoi(yytext));}

%%

int yywrap()
{
	return 1;
}

main()
{
	yylex();
	return 0;
}
