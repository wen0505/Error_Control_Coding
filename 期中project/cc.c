/* C語言實現序列卷積 */ 
#include<stdio.h>
#define MATRIX_DIM 1024
#define FILTER 32
int main(){
//初始化引數
	float result[MATRIX_DIM + FILTER - 1];
	float a_in[FILTER];
	float b_in[MATRIX_DIM];
	float c_in[MATRIX_DIM + FILTER - 1];
	for (int i = 0; i < MATRIX_DIM; i++) {
		b_in[i] = i;
	}
	for (int i = 0; i < MATRIX_DIM + FILTER -1; i++) {
		c_in[i] = 0;
		result[i] = 0;
	}
	for (int i = 0; i < FILTER; i++) {
		a_in[i] = i*1.0;
	}
	for (int j = 0; j < MATRIX_DIM+FILTER-1 ; j++) {
		for (int k = 0; k < MATRIX_DIM; k++) {
		if ( (j - k) >= 0 && (j - k) < FILTER) {
			c_in[j] += a_in[j - k] * b_in[k];
			}		
		}
	}
return 0;
}
