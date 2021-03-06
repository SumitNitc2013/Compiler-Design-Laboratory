%{
	#include <stdio.h>
	#include <math.h>
	#include <stdlib.h>
	extern FILE *yyin;
%}

%token NUM PLUS MINUS MUL DIV MOD
%left PLUS MINUS
%left MUL DIV
%left MOD

%%  
	start: expr '\n'       {printf("%d\n",$1);}
	     ;
	expr: expr PLUS expr     {$$=$1+$3;}
	    | expr MINUS expr    {$$=$1-$3;}
	    | expr MUL expr     {$$=$1*$3;}
	    | expr DIV expr 	{   if($3==0)
			        		{
		        				printf("Division by 0 is undefined\n");
		        				exit(0);
		        			}
		        	   else
		        		        {
		        				$$=$1/$3;
		        			}
        			} 
        							 
        | expr MOD expr		 {$$=$1%$3;}
        | '('expr')'    	{$$=$2;}
 	|  NUM			{$$=$1;}
	;
%%

 yyerror(const char* x)
{
	printf("error %s\n",x);
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

 	

	
