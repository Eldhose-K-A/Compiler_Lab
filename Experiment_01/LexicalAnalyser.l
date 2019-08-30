%{
	#include<stdio.h>
	#include<stdlib.h>
	int lineno=1;
%}

%%

"void"|"int"|"break"|"char"|"float"|"return"|"for"|"while"|"long"|"const" 	{ printf("\n%3d.\t%-20s\tKeyword",lineno,yytext); }
[0-9]+ 										{ printf("\n%3d.\t%-20s\tNumber",lineno,yytext); }
("_")*[a-zA-Z]("_"|[a-zA-Z]|[0-9])* 						{ printf("\n%3d.\t%-20s\tIdentifier",lineno,yytext); }
"+"|"-"|"*"|"/"|"%" 								{ printf("\n%3d.\t%-20s\tArithemetic Operator",lineno,yytext); }
"=" 										{ printf("\n%3d.\t%-20s\tAssignment Operator",lineno,yytext); }
"{"|"}"|"("|")"|"."|";"|"," 							{ printf("\n%3d.\t%-20s\tSeparator",lineno,yytext); }
"\n" 										{ lineno++; }

%%

int main(int argc,char *argv[]){
	FILE *f1;
	f1 = fopen(argv[1],"r");
	if(!f1){
		printf("Input File Not Found!.....");
		return 0;
	}
	yyin = f1;
	yylex();
	fclose(f1);
	printf("\n");
	return 0;
}
