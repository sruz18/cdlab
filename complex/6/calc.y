%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
S : E '\n' { printf("Result = %d\n", $1); return 0; }
  ;

E : E '+' E   { $$ = $1 + $3; }
  | E '-' E   { $$ = $1 - $3; }
  | E '*' E   { $$ = $1 * $3; }
  | E '/' E   { $$ = $1 / $3; }
  | '(' E ')' { $$ = $2; }
  | NUM       { $$ = $1; }
  ;
%%

int main() {
    printf("Enter expression:\n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid Expression\n");
}