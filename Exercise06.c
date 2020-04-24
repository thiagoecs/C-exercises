/*
 * Exercise06.c
 *
 *  Created on: Sep 9, 2019
 *      Author: thiag
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void caesar(char *string, int shift);

int main (){
	int i = 0;
	char string[100];
	int shift = 0;

	printf("Enter a phrase: \n");
	fgets(string, 100, stdin);
	if(string[strlen(string) -1] == '\n'){
		string[strlen(string)-1] = '\0';
	}
	printf("Enter the amount to shift: \n");
	scanf("%d", &shift);

	for(i=0; string[i] != '\0'; i++){
		if(string[i] >= 'a' && string[i] <= 'z'){
			string[i] = toupper(string[i]);

		}
	}

	printf("%s", string);

	caesar(string, shift);
	printf("%s", string);

	caesar(string, -shift);
	printf("%s", string);


}

void caesar(char *string, int shift){
	int i =0;

	while(string[i] != '\0'){
		if(isalpha(string[i])){
			string[i] = string[i] + shift;
			if(string[i] >'Z'){
				string[i] -= 25;
			}
			if(string[i] < 'A'){
				string[i] +=25;
			}

		}
		i++;
	}

}
