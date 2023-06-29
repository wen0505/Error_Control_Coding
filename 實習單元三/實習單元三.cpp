#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{	
	int m[4]={1,1,0,1},i;
	int x1=1,x2=1,x3=0,x4=1;
	int r11=0,r12=0,r13=0;
	int r21,r22,r23;
	int r31,r32,r33;
	int r41,r42,r43;
	int r51,r52,r53;
	int c1,c2,c3,c4,c5,c6,c7;
	int r1[3],r2[3],r3[3],r4[3];
	
	r21=(r13+x1)%2;
	r22=(x1+r11+r13)%2;
	r23=r12; 
	c1=x1;
	r1[0]=r21;
	r1[1]=r22;
	r1[2]=r23;
	
	r31=(r23+x2)%2;
	r32=(x2+r21+r23)%2;
	r33=r22; 
	c2=x2;
	r2[0]=r31;
	r2[1]=r32;
	r2[2]=r33;
	
	r41=(r33+x3)%2;
	r42=(x3+r31+r33)%2;
	r43=r32; 
	c3=x3;
	r3[0]=r41;
	r3[1]=r42;
	r3[2]=r43;
	
	r51=(r43+x4)%2;
	r52=(x4+r41+r43)%2;
	r53=r42; 
	c4=x4;
	r4[0]=r51;
	r4[1]=r52;
	r4[2]=r53;
	
	c5=r53;
	c6=r52;
	c7=r51;
	printf("r1 = ");
	for(i=0;i<3;i++){
		printf("%d ",r1[i]);
	}
	printf("\nr2 = ");
	for(i=0;i<3;i++){
		printf("%d ",r2[i]);
	}
	printf("\nr3 = ");
	for(i=0;i<3;i++){
		printf("%d ",r3[i]);
	}
	printf("\nr4 = ");
	for(i=0;i<3;i++){
		printf("%d ",r4[i]);
	}
	printf("\nc = %d %d %d %d %d %d %d ",c7,c6,c5,c4,c3,c2,c1);
	
	
	
	return 0;



}
