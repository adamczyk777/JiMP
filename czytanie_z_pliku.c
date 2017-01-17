#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    while(word[0] < 65 || (word[0] > 90 && word[0] < 97) || word[0] > 122){
        for(j=0;word[j] != '\0'; j++){
            word[j] = word[j+1];
        }
    }
}

struct word* read(FILE *file){
    char buffer[100];
    char *word;
    struct word *head;
    while(fscanf(file, "%s", buffer) != EOF){
        lowercase(buffer);
        trim_non_alpha(buffer);
        puts(buffer);
    }
    return head;
}

int main(void){
    FILE *fp;
    fp = fopen("tekst.txt", "r");

    read(fp);
    return 0;
}