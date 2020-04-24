/*
 * Exercise11.c
 *
 *  Created on: Oct 2, 2019
 *      Author: thiag
 */

#include <stdio.h>
#define LEN 3

int main(){
	int number[LEN];
	int i = 0;
	int j = 0;
	int temp = 0;

	FILE *fp = fopen("exercise11.txt", "r+");
	if (fp == NULL){
		return 1;
	}

	for(i = 0; i < LEN; i++ ){
		fscanf(fp, "%d", &number[i]);
	}

	for (i = 0; i < LEN; i++){
		for(j = i+1; j < LEN; j++){
			if(number[i] > number[j]){
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}
	}
	rewind(fp);
	for (i=0; i < LEN; i++){
		fprintf(fp, "%d\n", number[i]);
	}
	fclose(fp);
	return 0;

}
