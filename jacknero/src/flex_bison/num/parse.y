%{
#include <stdio.h>
%}
%union {
  double number_;
}
%token <number_> NUMBER
%type <number_> expr,additive_expr,multiplicative_expr,primary
%%
answer
  : expr
  { printf("answer=%f\n", $1); }
  ;
expr
  : additive_expr
  ;
additive_expr
  : multiplicative_expr
  | additive_expr '+' multiplicative_expr
  { $$ = $1 + $3; }
  | additive_expr '-' multiplicative_expr
  { $$ = $1 - $3; }
  ;
multiplicative_expr
  : primary
  | multiplicative_expr '*' primary
  { $$ = $1 * $3; }
  | multiplicative_expr '/' primary
  { $$ = $1 / $3; }
  ;
primary
  : NUMBER
  | '(' expr ')'
  { $$ = $2; }
  ;
%%
int yywrap() { return 0; }
int main() { yyparse(); return 0; }
