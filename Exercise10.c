/*
 * Exercise10.c
 *
 *  Created on: Oct 2, 2019
 *      Author: thiag
 */

#include <stdio.h>

int main (){
	FILE *fp;
	char data[30];
	int count = 0;
	int first_number = 0;
	double sum = 0;
	double number = 0;

	fp = fopen("test.txt", "r");
	if (fp == NULL){
		printf("Could not open file test.txt\n");
		return 0;
	}
	fgets(data, 30, fp);
	sscanf(data, "%d", &first_number);

	while(fgets(data, 30, fp)){
		if(sscanf(data, "%lf", &number)){
			sum += number;
			count++;
		}
	}

	if(count == first_number){
		printf("The average of %d numbers is: %.2f\n", count, sum/count);
	}
	else {
		printf("Error! Tried to read %d numbers, %d numbers were read.\n",first_number, count);
		printf("The average of %d numbers is: %.2f\n", count, sum/count);
	}
	fclose(fp);
	return 0;

}
