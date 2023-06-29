/* Convolutional Code */

#include <math.h> 
#include <stdio.h> 

int main()
{
	int i,j,k,n,gb,mb,g[10][10],x[10][10],c[10],m[10],t[10];
	clrscr();
	for(i=0;i< 10;i++){
		for(j=0;j< 10;j++){
			g[i][j]=0;
			x[i][j]=0;
			c[i]=0;
			m[i]=0;
			t[i]=0;
		}
	}
	printf("\t\t\t| Convolutional Code |");
	printf("\n\nEnter The No. Of Generator Sequences\t: ");
	scanf("%d",&n);
	printf("Enter The No. Of Bits In Each Generator Sequence\t: ");
	scanf("%d",&gb);
	for(i=0;i< n;i++){
		printf("\n\nEnter The Values Of G%d\t:\n",i);
		for(j=0;j< gb;j++)
			scanf("%dt",&g[i][j]);
	}
	printf("\nEnter The No. Of Message Bits\t: ");
	scanf("%d",&mb);
	printf("Enter The Message Bits\t:\n");
	for(i=0;i< mb;i++)
		scanf("%d",&c[i]);
	for(i=0;i< mb;i++){
		for(j=0;j< gb;j++){
			t[j]=m[j];
			if(j==0)
				m[j]=c[i];
			else
				m[j]=t[j-1];
		}
		for(k=0;k< gb;k++){
			for(j=0;j< gb;j++){
				if(g[k][j]==1)
					x[k][i]=x[k][i]^m[j];
			}
		}
	}
	printf("\n\n| The Code Vectors Are: |\n");
	for(i=0;i< mb;i++){
		printf("| \n| ");
		for(j=0;j< gb;j++)
			printf("%d\t",x[j][i]);
	}
	getch();
	
}

