#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Jakub Adamczyk 18.01.17

struct word {
    char *value;
    int reps; //repetitions of a certain word
    struct word *next;
};

void lowercase(char* word){
    int i;
    for(i=0;word[i];i++){
            word[i] = tolower(word[i]);
        }
}

void trim_non_alpha(char* word){
    int j;
    /* deleting non alphanumeric chars at beggining of the string*/
    while(word[0] < 65 || (word[0] > 90 && word[0] < 97) || word[0] > 122){
        for(j=0; word[j]!='\0'; j++){
            word[j] = word[j+1];
        }
        if(strlen(word) == 0){
            break;
        }
    }
    while(word[strlen(word)-1] < 65 || (word[strlen(word)-1] > 90 && word[strlen(word)-1] < 97) || word[strlen(word)-1] > 122){
        word[strlen(word)-1] = '\0';
        if(strlen(word) == 0){
            break;
        }
    }
}

void print_list(struct word* header){
    header = header->next;
    while(header->next != NULL){
        printf("Słowo: %s , Powtórzenia: %d \n", header->value, header->reps);
        header = header->next;
    }
}

struct word* read(FILE *file){
    char buffer[50];
    char *word;
    struct word *head = NULL;
    struct word *node;
    struct word *thruList = head;
    node = (struct word*)malloc(sizeof(struct word));
    node->next = NULL;
    node->value = NULL;
    node->reps = 0;
    head = node;
    while(fscanf(file, "%s", buffer) != EOF){
        thruList = head;
        trim_non_alpha(buffer);
        lowercase(buffer);
        while(thruList->next != NULL && strcmp(buffer, thruList->next->value)>0){
            thruList = thruList->next;
        }
        if(thruList->next != NULL && strcmp(buffer, thruList->next->value) == 0){
            thruList->next->reps++;
        }
        else{
            word = (char*)malloc(sizeof(char)*strlen(buffer));
            strcpy(word, buffer);
            node = (struct word*)malloc(sizeof(struct word));
            node->value = word;
            node->reps = 1;
            node->next = thruList->next;
            thruList-> next = node;
        }
        
    }
    return head;
}

int main(void){
    struct word *head;
    FILE *fp;
    fp = fopen("tekst.txt", "r");
    head = read(fp);
    print_list(head);
    return 0;
}
