/*
 * Exercise03.c
 *
 *  Created on: Sep 2, 2019
 *      Author: thiag
 */

#include <stdio.h>
#define STUDENT_COUNT 35

float average(int *grades, int students);

int main() {

	int students = 0;
	int grades[STUDENT_COUNT] = { 0 };
	int i = 0;


	printf("How many students have been graded!: \n");
	scanf("%d", &students);
	if (students<STUDENT_COUNT && students>0){
		for(i=0;i<students;i++){
			printf("enter grade for student nr. %d\n", i+45000);
			scanf("%d", &grades[i]);
			if (grades[i]>5 || grades[i]<0) {
				printf("only grades between 0 and 5 are accepted\n");
				i--;
			}

		}
		printf("Average grade of the students is: %.2f", average(grades, students));
	}


}


float average(int *grades, int students){
	int i =0;
	float sum=0;

	for(i=0;i<=students;i++){
		sum=sum+grades[i];

	}
	return sum/students;
}

