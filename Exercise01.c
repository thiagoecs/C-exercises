/*
 * Exercise01.c
 *
 *  Created on: Aug 29, 2019
 *      Author: thiag
 */

/*
===============================================================================
 Name        : Test01.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
 */



#include <stdio.h>

int main() {

	int number = 0;
	int i = 0;
	float sum = 0;
	float average = 0;


	while(i >= 0) {

		printf("Enter a number: \n");
		scanf("%d", &number);

		if(number<0) {
			printf("Only positive numbers are accepted\n");
		}

		else if(number>0){
			i++;
			sum = sum + number;
		}

		else{
			average = sum /i;
			printf("The average of your numbers is: %f\n", average);

			break;
		}
	}
}


