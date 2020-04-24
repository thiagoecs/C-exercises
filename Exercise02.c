/*
 * Exercise02.c
 *
 *  Created on: Aug 29, 2019
 *      Author: thiag
 */

#include <stdio.h>

int main(){
	float months[12];
	int i = 0;
	float income = 0;

	printf("Enter your yearly gross: \n");
	scanf("%f", &income);

	for (i = 0 ; i < 12 ; i++){
		if (i !=6 ) {
			months[i] = income/12.5;

		}
		else {
			months[6] = income/12.5 * 1.5;
		}
		printf("months[%02d] = %10.4f\n", i, months[i]);
	}
	printf("total      = %10.4f", income);
}
