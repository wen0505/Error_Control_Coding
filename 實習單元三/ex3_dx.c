/* (7,3)循環碼的編碼及解碼 */

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/* 函數說明 */
void Begin();
void Code();
void Decoding();
/* 主函數 */
main()
{
     printf("\n (7,3)循環碼的編碼及解碼\n ");
     Begin();
}
/* 編碼 */
void Code()
    {
     int Input[3];
     int Output[7];
     int reg[4]={0,0,0,0};
     int temp,i,j,t;
     printf("請輸入3位訊息（輸入3次，一次一位） :");
     for(i=0;i<3;i++)
     scanf(" %d",&Input[i]);                         /* 輸入3位訊息 */
     for(i=0;i<3;i++)                               /* 進行除法操作 */
        {temp=reg[3]+Input[i];               /* 生成多項式為g(x)=x^4+x^3+x^2+1 */ 
         if(temp==2) temp=0;
         reg[3]=reg[2]+temp;
         if(reg[3]==2)reg[3]=0;
         reg[2]=reg[1]+temp;
         if(reg[2]==2)reg[2]=0;
         reg[1]=reg[0];
         reg[0]=temp;
         }
     for(i=0;i<3;i++) Output[i]=Input[i];            /* 進行編碼操作 */
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
     printf(" 編碼結果: \n");
     for(i=0;i<7;i++)
     printf( "  %d  ",Output[i]);                          /* 輸出編碼結果 */
     printf("\n");
     printf("________________________________________");
     printf("\n");
     Begin();
     }
/* 解碼 */
void Decoding()
{ int Input[7],Output[7];
  int reg[4]={0,0,0,0,};
  int temp,i,d,x,p;
  printf("\n輸入7位數字（一次一位，輸入7次）:");
  for(i=0;i<7;i++)
  scanf("  %d",&Input[i]);                                 /* 輸入接收碼 */
  for(i=0;i<7;i++)                                         /* 進入除法電路 */
  {temp=reg[3];						   /* 計算伴隨式S(x) */
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
     {				          /* 輸入錯誤位數大于2位 */
      printf("    \"The error >=2\"  \n");
      getchar();
      exit(0);
      }
   printf("___________________________________________\n");
   printf("s(x)=");
  for(i=3;i>=0;i--)
   printf(" %d",reg[i]);
    printf("\n");
  for(i=0;i<7;i++)                                         /* 糾正一位錯誤 */
   {d=reg[3]*reg[2]*reg[1]*(!reg[0]);
   Output[i]=d+Input[i];
   if(Output[i]==2) Output[i]=0;
   temp=reg[3];
   x=0;							   /* S(x)進行自發計算以求得錯誤位數 */
   reg[3]=temp+reg[2];
   if(reg[3]==2)reg[3]=0;
   reg[2]=reg[1]+temp;
   if(reg[2]==2)reg[2]=0;
   reg[1]=reg[0];
   reg[0]=temp+x;
   }                                                       /* 輸出3位信息源 */
   printf("The decoding bit3 is:");
   for(i=0;i<3;i++)
   printf(" %d ",Output[i]);
   printf("\n");
   printf("The Decoding bit7 is:");                         /* 輸出7位解碼結果 */
   for(i=0;i<7;i++)
   printf(" %d ",Output[i]);
   printf("\n");
   printf("___________________________________________\n");
   Begin();
   }
/* 進行操作 */
 void Begin()
    {  
     fflush(stdin);                                             
     char ch;
     printf("    -----------------------------------------------------------------");
     printf("\n");
     printf("    --     輸入c開始編碼          --");
     printf("\n");
     printf("    --     輸入d開始解碼          --");
     printf("\n");
     printf("    --     輸入e離開程序          --");
     printf("\n");
     printf("    -----------------------------------------------------------------");
     printf("\n");
     ch=getchar();
     if(ch=='c') Code();
     else if(ch=='d') Decoding();
     else if(ch=='\n') Begin(); 
     else if(ch=='e') exit(0);
     else {printf("\"input error\"\n"); fflush(stdin);Begin();} /* 輸入錯誤提示 */   
    }
