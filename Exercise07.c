/*
 * Exercise07.c
 *
 *  Created on: Sep 9, 2019
 *      Author: thiag
 */

#include<stdio.h>
#include<ctype.h>
#include<string.h>

void conversion(char *string);

int main(){
	int a = 0;
	char string [100];
	do{
		printf("Enter a string: \n");
		fgets(string, 100, stdin);
		if(string[strlen(string) -1] == '\n'){
			string[strlen(string)-1] = '\0';
		}
		if(string[strlen(string) -1] == '\r'){
					string[strlen(string)-1] = '\0';
		}
		conversion(string);
		printf("%s", string);

	}
	while (strcmp(string, "stop") && strcmp(string, "STOP"));
}

void conversion (char *string){
	int i = 0;

	while(string[i] != '\0'){
		if(string[i] == ' '){
			string[i] = '_';
		}
		i++;
	}
}

