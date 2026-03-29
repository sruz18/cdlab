%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+      { yylval = atoi(yytext); return NUM; }

[+\-*/()]   { return yytext[0]; }

[ \t]       ;        // ignore spaces
\n          { return '\n'; }   // send newline to parser

.           { return yytext[0]; }
%%

int yywrap() {
    return 1;
}