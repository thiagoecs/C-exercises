/*
 * Exercise13.c
 *
 *  Created on: Oct 9, 2019
 *      Author: thiag
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char *buffer, *temp_buffer;
    int length = 16;

    fp = fopen("exercise13.txt", "w");
    if(!fp) {
        printf("Error opening file.");
        return 1;
    }

    buffer = malloc(length * sizeof(char));

    do {
        printf("Enter a string ('.' to end program): ");
        fgets(buffer, length, stdin);


        while(buffer[strlen(buffer)-1] != '\n'){

            if (temp_buffer = realloc(buffer, ++length * sizeof(char))) {
                buffer = temp_buffer;

                fgets(&buffer[strlen(buffer)], 2, stdin);
            } else {
                printf("Memory error. Printing partial input.\n");
                break;
            }
        }

        if(buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer) - 1] = '\0';

        if(*buffer != '.') {
            if(fprintf(fp, "%ld:%s\n", strlen(buffer), buffer) >= 0) {
                printf("\"%ld:%s\" successfully written to file.\n", strlen(buffer), buffer);
            } else {
                printf("Error writing to file.");
            }
        }

    } while (*buffer != '.');

    free(buffer);
    fclose(fp);
    printf("Program closed.\n");
    return 0;
}
