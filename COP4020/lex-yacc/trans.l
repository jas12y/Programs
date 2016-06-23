%{
   #include "y.tab.h"
   int put_string(char *str, int len);
   extern int yyline, yycolumn;
   char string_table[20000];
   int string_table_index = 0;
%}

delim     [ \t]
ws        {delim}+
letter    [a-zA-Z]
digit     [0-9]
id        {letter}({letter}|{digit})*
number    {digit}+

%%
\n             {yyline++;yycolumn=1;}
print          {yycolumn += yyleng; return (PRINTNUM);}
program        {yycolumn += yyleng; return (PROGRAMNUM);}
is             {yycolumn += yyleng; return (ISNUM);}
begin          {yycolumn += yyleng; return (BEGINNUM);}
end            {yycolumn += yyleng; return (ENDNUM);}
var            {yycolumn += yyleng; return (VARNUM);}
{ws}           {yycolumn += yyleng;}
if             {yycolumn += yyleng; return (IFNUM);}
"("            {yycolumn += yyleng; return (LPARENNUM);}
")"            {yycolumn += yyleng; return (RPARENNUM);}
;              {yycolumn += yyleng; return (SEMINUM);}
,              {yycolumn += yyleng; return (COMMANUM);}
then           {yycolumn += yyleng; return (THENNUM);}
{id}           {yycolumn += yyleng;
                yylval.sv = put_string(yytext, yyleng); 
                return (IDNUM);}
{number}       {yylval.sv = atoi(yytext); yycolumn += yyleng; return (INTEGERCONST);}
'[^'\n]*       {int c;
                yycolumn += yyleng;
                if (yyleng == 2) {
                   yylval.sv = put_string(yytext+1, yyleng-1);
                   c=input(); /* read the additional ' */
                   if (c != '\'') {
                      printf("unenclosed character, line = %d, column = %d\n", yyline, yycolumn-yyleng);
                      if (c != 0) unput(c);
                   } 
                   return(CHARCONST);
                 } else {
                   yylval.sv = put_string(yytext+1, yyleng-1);
                   c= input();
                   if (c != '\'') {
                      printf("unended string, line = %d, column = %d\n", yyline, yycolumn-yyleng);
                   if (c != 0) unput(c);
                 } 
                 return(STRINGCONST);
               }
              }
\+            {yycolumn += yyleng;return (PLUSNUM);}
"*"           {yycolumn += yyleng;return (TIMESNUM);}
"="           {yycolumn += yyleng;return(EQUALNUM);}
.             { printf("Unknown character %s, line = %d, column = %d\n", yytext, yyline, yycolumn);yycolumn += yyleng;}

%%

#include <stdio.h>
#include <string.h>

int yywrap()
{  if (feof(stdin)) return 1;
   return 0;
}

int put_string(char *str, int len)
{
  char buf[2000];
  strncpy(buf, str, len);
  buf[len] = '\0';
  sprintf(string_table+string_table_index, "%s", buf);
  string_table_index += strlen(buf)+1;
  string_table[string_table_index-1] = '\0';
  return (string_table_index-strlen(buf)-1);
}







