%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
%}

%token ID

%%
S : ID { printf("Valid Variable\n"); return 0; }
  ;
%%

int main() {
    printf("Enter variable:\n");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid Variable\n");
    exit(0);
}