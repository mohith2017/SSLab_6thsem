%{
  #include<stdio.h>
  int chars=0,words=0,spaces=0,lines=0;
%}
%%
[a-zA-Z0-9] {chars+=yyleng;words++;}
" " {spaces++;}
"\n" {lines++;}
. {chars++;}
%%

void main()
{
  yyin=fopen("input.txt","r");
  yylex();
  printf("Characters:%d\tWords:%d\tSpaces:%d\tLines:%d\n",chars,words,spaces,lines);
}
