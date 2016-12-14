#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read(char *strings[], int i){
    char buffer[100];
    fgets(buffer, 100, stdin);
    strings[i] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(strings[i], buffer);
}
void main(){
    char *strings[5];
    int i;
    for(i=0; i<5; i++){
        read(strings, i);
    }
    int n;
    for(n=0;n<5;n++){
        printf("%s", strings[n]);
        free(strings[n]);
    }
    free(*strings);
}
