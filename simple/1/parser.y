%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s);
%}

%%
S : A B
  | A
  ;

A : 'a' A
  | 'a'
  ;

B : 'b' B
  | 'b'
  ;
%%

int main() {
    printf("Enter string:\n");
    if (yyparse() == 0)
        printf("Valid String\n");
    return 0;
}

void yyerror(const char *s) {
    printf("Invalid String\n");
}