/* ex3_decoding_x.c */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{	
	int b1, b2, b3, b4, b5, b6, b7;
	int c0, c1, c2, c3, c4, c5, c6;
	int s01, s02, s03;
	int s11, s12, s13;
	int s21, s22, s23;
	int s31, s32, s33;
	int s41, s42, s43;
	int s51, s52, s53;
	int s61, s62, s63;

	b1=1; b2=0; b3=1; b4=1; b5=0; b6=1; b7=1;
	s01=0; s02=0; s03=1;
	c0=s01*(!s02)*s03;
	printf("receive code = %d  %d  %d  %d  %d  %d  %d ", (b1+c0)%2, b2, b3, b4, b5, b6, b7);
	s11=(s03+c0)%2;
	s12=(s01+s03)%2;
	s13=s02;
	c1=s11*(!s12)*s13;
	printf("\n1st shift    = %d  %d  %d  %d  %d  %d  %d ", (b7+c0)%2, (b1+c0)%2, b2, b3, b4, b5, b6);
	s21=(s13+c1)%2;
	s22=(s11+s13)%2;
	s23=s12;
	c2=s21*(!s22)*s23;  
	printf("\n2nd shift    = %d  %d  %d  %d  %d  %d  %d ", (b6+c1)%2, (b7+c1)%2, (b1+c0)%2, b2, b3, b4, b5);
	s31=(s23+c2)%2;
	s32=(s21+s23)%2;
	s33=s22;
	c3=s31*(!s32)*s33;
	printf("\n3rd shift    = %d  %d  %d  %d  %d  %d  %d ", (b5+c2)%2, (b6+c2)%2, (b7+c1)%2, (b1+c0)%2, b2, b3, b4);
	s41=(s33+c3)%2;
	s42=(s31+s33)%2;
	s43=s32;
	c4=s41*(!s42)*s43;
	printf("\n4th shift    = %d  %d  %d  %d  %d  %d  %d ", (b4+c3)%2, (b5+c3)%2, (b6+c2)%2, (b7+c1)%2, (b1+c0)%2, b2, b3);
	s51=(s43+c4)%2;
	s52=(s41+s43)%2;
	s53=s42;
	c5=s51*(!s52)*s53;
	printf("\n5th shift    = %d  %d  %d  %d  %d  %d  %d ", (b3+c4)%2, (b4+c3)%2, (b5+c3)%2, (b6+c2)%2, (b7+c1)%2, (b1+c0)%2, b2);
	s61=(s53+c5)%2;
	s62=(s51+s53)%2;
	s63=s52;
	c6=s61*(!s62)*s63;
	printf("\n6th shift    = %d  %d  %d  %d  %d  %d  %d ", (b2+c5)%2, (b3+c4)%2, (b4+c3)%2, (b5+c3)%2, (b6+c2)%2, (b7+c1)%2, (b1+c0)%2);
	printf("\ncorrect code = %d  %d  %d  %d  %d  %d  %d ", (b1+c0)%2, (b2+c5)%2, (b3+c4)%2, (b4+c3)%2, (b5+c3)%2, (b6+c2)%2, (b7+c1)%2);
	return 0;

}

