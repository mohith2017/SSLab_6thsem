%{
  #include<stdio.h>
  int id=0,operators=0,comments=0;
%}
%%
"//"+[a-zA-Z0-9] {comments++;}
^[a-zA-Z_][a-zA-Z0-9_]* {id++;}
[*/!+=()]* {operators++;}
%%

void main()
{
  yyin=fopen("input.c","r");
  yylex();
  printf("Identifiers:%d\tOperators:%d\tComments:%d\n",id,operators,comments);
}
