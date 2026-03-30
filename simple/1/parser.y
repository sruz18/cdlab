%{
    #include <stdio.h>
    #include <stdlib.h>


    int yylex();
    int yyerror(char const *c);
%}


%token ID

%left '+'
%left  '*'

%%
S : E '\n'   { return 0; }
  ;

E : E '+' T
  | T
  ;

T : F '*' T
  | F
  ;

F : '(' E ')'
  | ID
  ;
%%


int main(){
    printf("Enter the Expression:");
    if(yyparse()==0){
        printf("Valid\n");
    }
    return 0;
}

int yyerror(char const *s){
    printf("Invalid!\n");
    return 1;
}