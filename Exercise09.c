/*
 * Exercise09.c
 *
 *  Created on: Sep 28, 2019
 *      Author: thiag
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 12
#define ARRAY_LEN 15

struct car_rental {
	char car_make[LEN];
	char model[LEN];
	char category;
	char plate[LEN];
	int mileage;
	int available;
};

int changeStatus(struct car_rental cars[], int array_size, char plate[]);
void car_search(struct car_rental cars[], int array_size, char category, int print_all_cars);
void read_string(char *string);
int read_number();



int main () {

	struct car_rental cars[ARRAY_LEN] = {
	        {"Ford", "Fiesta", 'C', "LGH-190", 10390, 1},
	        {"Ford", "Focus", 'M', "ZHH-102", 8367, 0},
	        {"BMW", "M3", 'P', "AGH-487", 13120, 1},
	        {"BMW", "M4", 'M', "BJK-355", 3120, 1},
	        {"Toyota", "Corolla", 'X', "PFF-421", 4560, 0},
	        {"Toyota", "Camry", 'X', "OIO-909", 17801, 1},
	        {"Nissan", "Altima", 'M', "STL-550", 2231, 0},
	        {"Hyundai", "Accent", 'L', "PPQ-323", 7871, 0},
	        {"Honda", "Accord", 'V', "LRT-781", 4021, 1},
	        {"Mazda", "Mazda3", 'V', "VZD-202", 19220, 0},
	        {"Mitsubishi", "Lancer", 'X', "TFA-834", 7112, 0},
	        {"Nissan", "Armada", 'C', "QTY-211", 2354, 0},
	        {"Mazda", "Mazda3", 'C', "HUJ-254", 6531, 1},
	        {"Hyundai", "Elantra", 'P', "KLK-772", 11320, 1},
	        {"Honda", "Civic", 'L', "JDL-112", 11786, 0},
	    };

	int status = 0;
	int option = 0;
	char input [LEN];

	do {

	printf("1. print all cars\n");
	printf("2. print free cars of given category\n");
	printf("3. change status of a car\n");
	printf("4. quit the program\n");
	printf("Type a number for the desired service: \n");
	option = read_number();

	if(option == 1){
		car_search(cars, ARRAY_LEN, '*', 1);
	}

	else if(option == 2){
		printf("Enter category [C, L, M, P, V, X] or enter * to see all available cars: \n");
		read_string(input);
		car_search(cars, ARRAY_LEN, *input, 0);
	}

	else if(option == 3){
		printf("Enter the plate you want to modify: \n");
		read_string(input);
		if(status = changeStatus(cars, ARRAY_LEN, input)){
			printf("A car with license plate %s was found and is now marked as ", input);
			if(status == 2){
				printf("available\n");
			}
			else if(status == 1){
				printf("not available\n");
			}
		}
		else {
			printf("Car not found\n");
		}

	}
	else if (option == 4) {
		printf("Shutting down \n");
	}
	else {
		printf("invalid input\n");
	}

	}
	while (option !=4);
}





void car_search(struct car_rental cars[], int array_size, char category, int print_all_cars){
	printf("%-10s|%-7s|%-6s|%-7s|%8s\n", "Make", "Model", "Cat.", "Plate", "Mileage");
	for(int i = 0; i < array_size; i++){
    if( ((category == cars[i].category) || category == '*')  &&  (cars[i].available || print_all_cars) ) {
        printf("%-10s|%-7s|%-6c|%-7s|%8d\n", cars[i].car_make, cars[i].model, cars[i].category, cars[i].plate, cars[i].mileage);
    }
}
}
int changeStatus (struct car_rental cars[], int array_size, char plate[]){
	for(int i = 0; i < array_size; i++){
		if(!strcmp(cars[i].plate, plate)){
			cars[i].available = !cars[i].available;
			return 1 + cars[i].available;
		}
	}
}


void read_string(char *string){
    fgets(string, LEN, stdin);
    if(string[strlen(string)-1] == '\n')
        string[strlen(string)-1] = '\0';
}

int read_number() {
    int number = 0;
    char input[LEN];
    fgets(input, LEN, stdin);
    sscanf(input, "%d", &number);
    return number;
}
