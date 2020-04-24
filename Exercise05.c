/*
 * Exercise05.c
 *
 *  Created on: Sep 5, 2019
 *      Author: thiag
 */

#include <stdio.h>
void multiplication (int *vector, int matrix[][3], int *result);

int main() {

	int vector [3];
	int matrix [3][3];
	int result [3];
	int r = 0;
	int c = 0;

	for (r=0; r<3; r++){
		printf("Enter the value for vector [%d]: \n", r);
		scanf("%d", &vector[r]);
	}
	for ( r=0 ; r<3 ; r++) {
		for (c=0 ; c<3; c++){

			printf("Enter a 3 by 3 matrix value: [%d][%d] \n", r, c);
			scanf("%d", &matrix[r][c]);

		}
	}
	for (r=0; r<3; r++){
		printf("%d \n", vector[r]);
	}
	for (r=0; r<3; r++){
		for (c=0; c<3; c++){
			printf("%d ", matrix[r][c]);
		}
		printf("\n");
	}
	multiplication(vector, matrix, result);
	for (r=0; r<3; r++){
		printf("%d \n", result[r]);

	}
}

void multiplication (int *vector, int matrix[][3], int *result) {
	int r = 0;
	int c = 0;
	int sum = 0;

	for (r=0; r<3; r++) {
		sum =0;
		for (c=0; c<3; c++) {
			sum = sum + (vector[c] * matrix [r][c]);

		}
		result[r] = sum;
	}

}

