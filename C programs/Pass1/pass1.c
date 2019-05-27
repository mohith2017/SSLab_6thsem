#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
  FILE *f1,*f2,*f3,*f4;
  char label[10],opcode[10],next_value[10],opcode1[10],value1[10];
  int loc=0,operand,start_addr;

  f1=fopen("Input.dat","r");
  f2=fopen("Optab.dat","r");
  f3=fopen("Symtab.dat","w");

  fscanf(f1,"%s %s %x",label,opcode,&operand);

  if(strcmp(opcode,"START")==0)
  {
    start_addr=operand;
    loc=start_addr;
    printf("\t%s\t%s\t%x\n",label,opcode,operand);
  }

  else
    loc=0;

   fscanf(f1,"%s %s",label,opcode);


  while(!feof(f1))
  {
    fscanf(f1,"%s",next_value);
    printf("%x\t%s\t%s\t%s\n",loc,label,opcode,next_value);
    if(strcmp(label,"-")!=0)
    {
      fprintf(f3, "%x\t%s\n",loc,label);
    }

    fscanf(f2,"%s%s",opcode1,value1);

    while(!feof(f2))
    {
      if(strcmp(opcode,opcode1)==0)
      {
        loc=loc+3;
        break;
      }
      fscanf(f1,"%s%s",opcode1,value1);
    }

    if(strcmp(opcode,"WORD")==0)
    {
      loc=loc+3;
    }

    if(strcmp(opcode,"RESB")==0)
    {
      loc=loc+atoi(next_value);
    }

    if(strcmp(opcode,"RESW")==0)
    {
     loc=loc+(3*atoi(next_value));
    }

    if(strcmp(opcode,"BYTE")==0)
    {
      if(strcmp(next_value,"X")==0)
         loc=loc+1;
      else
        loc=loc+strlen(next_value)-2;
    }
    fscanf(f1,"%s%s",label,opcode);
  }

  if(strcmp(opcode,"END")==0)
  {
    printf("Length of program: %d\n",(loc-start_addr));
  }


  fclose(f1);
  fclose(f2);
  fclose(f3);
}
