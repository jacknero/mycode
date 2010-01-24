%{
#include<stdio.h>
%}
%%
  [0-9][0-9]* {printf("number:%d\n",atoi(yytext));}
  [a-zA-Z][0-9a-zA-Z]* {printf("string:%s\n", yytext);}
%%
int main()
{
  yylex();
  return 0;
}
