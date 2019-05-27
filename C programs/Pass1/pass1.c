//Pass 1 of 2 pass assembler
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
FILE *f1,*f2,*f3,*f4;
int loc,start_addr,l,operand,value1,len;
char opcode[20],label[20],next_value[20],opcode1[20];

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
      printf("\n%x\t%s\t%s\t%s\n",loc,label,opcode,next_value);
      if(strcmp(label,"-")!=0)
        fprintf(f3,"\n%x\t%s\n",loc,label);


      fscanf(f2,"%s %d",opcode1,&value1);

      while(!feof(f2))
      {
        if(strcmp(opcode,opcode1)==0)
        {
         loc=loc+3;
         break;
        }
        fscanf(f2,"%s %d",opcode1,&value1);

       }

      if(strcmp(opcode,"WORD")==0)
         loc=loc+3;

      else if(strcmp(opcode,"RESW")==0)
      {
       operand=atoi(next_value);
       loc=loc+(3*operand);
      }

      else if(strcmp(opcode,"BYTE")==0)
      {
       if(next_value[0]=='X')
         loc=loc+1;

       else
       {
         len=strlen(next_value)-2;
         loc=loc+len;
       }
      }

       else if(strcmp(opcode,"RESB")==0)
       {
        operand=atoi(next_value);
        loc=loc+operand;
       }

       fscanf(f1,"%s%s",label,opcode);
     }

 if(strcmp(opcode,"END")==0)
   printf("Program length =\n%d",loc-start_addr);

fclose(f1);
fclose(f2);
fclose(f3);
}
