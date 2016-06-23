%{
#include "y.tab.h"
%}

%%
[a-zA-Z]+ {yylval.string=yytext; printf("scanned the number %s\n", yylval);return NAME;}
[0-9]+   { yylval.number = atoi (yytext); printf ("scanned the number %d\n", yylval);return NUMBER; }
[ \t] { printf ("skipped whitespace\n"); }
\n   { printf ("reached end of line\n");
return 0;
}
.     { printf ("found other data \"%s\"\n", yytext);
return yytext[0];
/* so yacc can see things like '+', '-', and '=' */
}
%%
