%{
   #include "y.tab.h"
   int put_string(char *str, int len);
   int string_table_index = 0;
   extern char string_table[20000];
  
%}


letter    [a-zA-Z]
digit     [0-9]
id        {letter}({letter})*({digit})*

%%

{id}       {//printf("Picked up a string: yytext is %s and yyleng is %d \n", yytext, yyleng);
            yylval.sv = put_string(yytext, yyleng);
            return(IDnumber);}

{digit}+   {//printf("Picked up a number. \n");
            yylval.sv = atoi(yytext);
            return(ICONSTnumber);}

=          {//printf("Picked up an equal sign. \n");
            return(EQUALnumber);}

.         
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
  //printf("In buf: %s \n", buf);
  sprintf(string_table+string_table_index, "%s", buf);
  //printf("In string_table[string_table_index]: %s \n", string_table+string_table_index);
  string_table_index += strlen(buf)+1;
  string_table[string_table_index-1] = '\0';
  return (string_table_index-strlen(buf)-1);
}
