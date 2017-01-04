#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct book {
        char nameSurname[100];
        char title[100];
        int catNo;
        double price;
    };

void main(void){
    int quantity, i;
    printf("wpisz liczbe pozycji w tablicy: \n");
    scanf("%d", &quantity);
    struct book* booksArray;
    booksArray = malloc(sizeof(booksArray) * quantity);
    for(i = 0; i < quantity; i++){
        scanf("%s", booksArray[i].nameSurname);
        scanf("%s", booksArray[i].title);
        scanf("%d", &booksArray[i].catNo);
        scanf("%lf", &booksArray[i].price);
    }
}