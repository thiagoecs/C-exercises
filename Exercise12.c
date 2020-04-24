#include <stdio.h>
#include <string.h>
#define STOCK_LEN 20
#define LEN 50

struct price_info {
    double price;
    char name[LEN];
};

int main(){
    char buffer[LEN];
    int count = 0, longest = 0;
    struct price_info stock[STOCK_LEN];

    printf("Input filename: ");
    fgets(buffer, LEN, stdin);
    if(buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = '\0';
    if(buffer[strlen(buffer) - 1] == '\r')
            buffer[strlen(buffer) - 1] = '\0';

    FILE *fp = fopen(buffer, "r");
    if (!fp){
        printf("Unable to open file.\n");
        return 1;
    }

    while(!feof(fp) && count < STOCK_LEN){
        fgets(buffer, LEN, fp);
        if(sscanf(buffer, "%lf;%[^\n]", &stock[count].price, stock[count].name) == 2){
            if(strlen(stock[count].name) > longest)
                longest = strlen(stock[count].name);
            count++;
        }
    }
    printf("Number of items found: %d\n", count);
    printf("%-*s %8s\n", longest, "Name", "Price");
    for(int i = 0; i < count; i++){
        printf("%-*s %8.2lf\n", longest, stock[i].name, stock[i].price);
    }
    return 0;
}
