#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(void){
    int quantity;
    scanf("%d", &quantity);
    struct book{
        char nameSurname[];
        char title[];
        int catNo;
        float price;
    };
    struct book books[quantity];
}