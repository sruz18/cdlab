%{
#include <stdio.h>

int w = 0;
int l = 0;
%}

%%
\n              { l++; }                 // count lines

[ \t]+          ;                           // ignore spaces/tabs

[^ \t\n]+       { w++; }                // count words

%%

int main() {
    printf("Enter text (Ctrl+D to stop):\n");
    yylex();

    printf("Number of lines: %d\n", l);
    printf("Number of words: %d\n", w);

    return 0;
}

int yywrap() {
    return 1;
}