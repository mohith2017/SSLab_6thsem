%{
  #include<stdio.h>
  int id=0,operators=0,comments=0;
%}

%%
//[a-zA-Z0-9]+// {comments++;}
%%

void main()
{
  yyin=fopen("input.c","r");
  yylex();
  printf("Identifierss:%d\tOperators:%d\tComments:%d\n",id,operators,comments);
}
