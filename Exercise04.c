/*
 * Exercise04.c
 *
 *  Created on: Sep 5, 2019
 *      Author: thiag
 */


#include <stdio.h>

int main() {

	int currentHour = 0;
	int currentMinute = 0;
	int sleepingHour = 0;
	int sleepingMinute = 0;
	int wakeHour = 0;
	int wakeMinute = 0;

	printf("Enter current time: \n");
	scanf("%2d:%2d", &currentHour, &currentMinute);

	if(currentHour > 23 || currentMinute > 59) {
		printf("Invalid values\n");
	}
	else {
		printf("How long do you want to sleep!\n");
		scanf("%d:%2d",&sleepingHour, &sleepingMinute);
		if (sleepingHour > 23 || sleepingMinute > 59) {
			printf("Invalid values\n");
		}
		else {
			wakeHour = currentHour + sleepingHour;
			wakeMinute = currentMinute + sleepingMinute;
			if(wakeMinute > 59){
				wakeMinute -= 60;
				wakeHour++;
			}
			if (wakeHour > 23){
				wakeHour -= 24;
			}
		}
	}
	printf("If you go to bed now you will need to wake up at %02d:%02d\n", wakeHour, wakeMinute);
}
