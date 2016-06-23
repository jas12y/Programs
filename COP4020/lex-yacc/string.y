%{
  #include <stdio.h>
  char string_table[20000];
%}

%union {
  int sv;
  struct {
    int v;
    char s[1000];
  } attr;
}
     
%token   <sv> ICONSTnumber
%token   <sv> IDnumber                 
%token   EQUALnumber

%type <attr> exp

%%

prog:     exp prog
          | exp
          ;

exp:      IDnumber EQUALnumber ICONSTnumber {printf("Assigning %d to %s\n",  $3, string_table+$1);}

%%

#include <stdio.h>

void yyerror(const char *str)
{    printf("Error.\n");
}

int main()
{
  if (!yyparse()){
    printf("accept\n");
  }
  else printf("reject\n");
}    



