/*
 * exercise08.c
 *
 *  Created on: Sep 28, 2019
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
		printf("%s\n", string);

	}
	while (strcmp(string, "stop") && strcmp(string, "STOP"));
}

void conversion (char *string){
	int i = 0;

	string[0] = toupper(string[0]);
	while(string[i] != '\0'){
		if(string[i-1] == ' '){
			string[i]= toupper(string[i]);
		}
		i++;
	}
}

