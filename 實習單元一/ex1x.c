/* ex1xx.c */

#include <math.h> 
#include <stdio.h> 
  
void main() {
    int x[10], y[10];
    int A, B, C, e, i;
 
    printf("Enter 4 bits of x:\n");
    scanf("%d", &x[0]);
    scanf("%d", &x[1]);
    scanf("%d", &x[2]);
    scanf("%d", &x[4]);
 
    //Calculation of even parity
    x[3] = x[0]^x[1]^x[2];
	x[5] = x[0]^x[1]^x[4];
	x[6] = x[0]^x[2]^x[4];
 
	printf("\nEncoded x is:\n");
	for(i=0; i<7; i++)
        printf("%d", x[i]);
 
    printf("\n\nEnter received x:\n");
    for(i=0; i<7; i++)
        scanf("%d", &y[i]);
 
    A = y[6]^y[4]^y[2]^y[0];
	B = y[5]^y[4]^y[1]^y[0];
	C = y[3]^y[2]^y[1]^y[0];
	e = C*4 + B*2 + A;
 
    if(e == 0) {
		printf("\nNo error\n");
    }
	else {
		printf("\nError on position %d",e);
    	
		printf("\nData sent : ");
        for(i=0; i<7; i++)
        	printf("%d", x[i]);
        
		printf("\nA is %d", A);
		printf("\nB is %d", B);
		printf("\nC is %d", C);
        
		printf("\nData received : ");
        for(i=0; i<7; i++)
        	printf("%d",y[i]);
        	
		printf("\nCorrect message is ");
 
		//if errorneous bit is 0 we complement it else vice versa
		if(y[7-e] == 0)
			y[7-e]=1;
        else
			y[7-e]=0;
		
		for (i=0; i<7; i++) {
			printf("%d", y[i]);
		}
	}
}
