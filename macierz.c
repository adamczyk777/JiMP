#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Jakub Adamczyk Zadanie Kolokwium */
struct node{
    int row;
    int column;
    double value;
    struct node* next;
};

struct min_max{
    double min;
    double max;
};

struct node* konwersja(double mac[5][5], int rows, int cols){
    int i, j;
    struct node* wsk = NULL;
    struct node* el;


    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            if(mac[i][j] != 0){
                el = (struct node*)malloc(sizeof(struct node));
                el->row = i;
                el->column = j;
                el->value = mac[i][j];
                el->next = wsk;
                wsk = el;
            }
        }
    }

    return wsk;
}

struct min_max znajdz_min_max(struct node* point){
    struct min_max result;
    result.min = 1000000;
    result.max = 0;
    while(point != NULL){
        if(point->value > result.max){
            result.max = point->value;
        }
        if(point->value < result.min){
            result.min = point->value;
        }
        point = point->next;
    }
    return result;
}

void drukuj(struct node* elem){
    while(elem != NULL){
        printf("Kolumna: %d\n", elem->column);
        printf("Wiersz: %d\n", elem->row);
        printf("Wartosc: %.2lf \n\n", elem->value);
        elem = elem->next;
    }
}

int main(void){
    double macierz[5][5] = 
    {{1,0,0,0,0}, 
    {0,1,0,0,0}, 
    {0,0,1,0,0}, 
    {0,0,0,1,0}, 
    {0,0,0,0,1}};
    struct node* head;
    struct min_max wartosciMinMax;

    head = konwersja(macierz, 5, 5);
    drukuj(head);

    wartosciMinMax = znajdz_min_max(macierz);
    printf("Wartosc min:\n Kolumne : %d\nWiersz: %d\nWartosc: %.2lf\n", wartosciMinMax.min);
    printf("")

    return 0;
}