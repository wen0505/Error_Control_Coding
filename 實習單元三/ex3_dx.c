/* (7,3)�`���X���s�X�θѽX */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/* ��ƻ��� */
void Begin();
void Code();
void Decoding();
/* �D��� */
main()
{
     printf("\n (7,3)�`���X���s�X�θѽX\n ");
     Begin();
}
/* �s�X */
void Code()
    {
     int Input[3];
     int Output[7];
     int reg[4]={0,0,0,0};
     int temp,i,j,t;
     printf("�п�J3��T���]��J3���A�@���@��^ :");
     for(i=0;i<3;i++)
     scanf(" %d",&Input[i]);                         /* ��J3��T�� */
     for(i=0;i<3;i++)                               /* �i�氣�k�ާ@ */
        {temp=reg[3]+Input[i];               /* �ͦ��h������g(x)=x^4+x^3+x^2+1 */ 
         if(temp==2) temp=0;
         reg[3]=reg[2]+temp;
         if(reg[3]==2)reg[3]=0;
         reg[2]=reg[1]+temp;
         if(reg[2]==2)reg[2]=0;
         reg[1]=reg[0];
         reg[0]=temp;
         }
     for(i=0;i<3;i++) Output[i]=Input[i];            /* �i��s�X�ާ@ */
     for(i=3;i<7;i++)
        {
         temp=reg[3];
         for(j=3;j>0;j--)
             reg[j]=reg[j-1];
             reg[0]=0;
             Output[i]=temp;
         }
     printf("________________________________________");
     printf("\n");
     printf(" �s�X���G: \n");
     for(i=0;i<7;i++)
     printf( "  %d  ",Output[i]);                          /* ��X�s�X���G */
     printf("\n");
     printf("________________________________________");
     printf("\n");
     Begin();
     }
/* �ѽX */
void Decoding()
{ int Input[7],Output[7];
  int reg[4]={0,0,0,0,};
  int temp,i,d,x,p;
  printf("\n��J7��Ʀr�]�@���@��A��J7���^:");
  for(i=0;i<7;i++)
  scanf("  %d",&Input[i]);                                 /* ��J�����X */
  for(i=0;i<7;i++)                                         /* �i�J���k�q�� */
  {temp=reg[3];						   /* �p����H��S(x) */
   reg[3]=reg[2]+temp;
   if(reg[3]==2)reg[3]=0;
   reg[2]=reg[1]+temp;
   if(reg[2]==2)reg[2]=0;
   reg[1]=reg[0];
   reg[0]=temp+Input[i];
   if(reg[0]==2)reg[0]=0;
  }
   p=reg[3]+2*reg[2]+4*reg[1]+8*reg[0];
   if(p!=1&&p!=2&&p!=3&&p!=7&&p!=8&&p!=13&&p!=14&&p!=0)
     {				          /* ��J���~��Ƥj�_2�� */
      printf("    \"The error >=2\"  \n");
      getchar();
      exit(0);
      }
   printf("___________________________________________\n");
   printf("s(x)=");
  for(i=3;i>=0;i--)
   printf(" %d",reg[i]);
    printf("\n");
  for(i=0;i<7;i++)                                         /* �ȥ��@����~ */
   {d=reg[3]*reg[2]*reg[1]*(!reg[0]);
   Output[i]=d+Input[i];
   if(Output[i]==2) Output[i]=0;
   temp=reg[3];
   x=0;							   /* S(x)�i��۵o�p��H�D�o���~��� */
   reg[3]=temp+reg[2];
   if(reg[3]==2)reg[3]=0;
   reg[2]=reg[1]+temp;
   if(reg[2]==2)reg[2]=0;
   reg[1]=reg[0];
   reg[0]=temp+x;
   }                                                       /* ��X3��H���� */
   printf("The decoding bit3 is:");
   for(i=0;i<3;i++)
   printf(" %d ",Output[i]);
   printf("\n");
   printf("The Decoding bit7 is:");                         /* ��X7��ѽX���G */
   for(i=0;i<7;i++)
   printf(" %d ",Output[i]);
   printf("\n");
   printf("___________________________________________\n");
   Begin();
   }
/* �i��ާ@ */
 void Begin()
    {  
     fflush(stdin);                                             
     char ch;
     printf("    -----------------------------------------------------------------");
     printf("\n");
     printf("    --     ��Jc�}�l�s�X          --");
     printf("\n");
     printf("    --     ��Jd�}�l�ѽX          --");
     printf("\n");
     printf("    --     ��Je���}�{��          --");
     printf("\n");
     printf("    -----------------------------------------------------------------");
     printf("\n");
     ch=getchar();
     if(ch=='c') Code();
     else if(ch=='d') Decoding();
     else if(ch=='\n') Begin(); 
     else if(ch=='e') exit(0);
     else {printf("\"input error\"\n"); fflush(stdin);Begin();} /* ��J���~���� */   
    }
