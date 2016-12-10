#include <stdio.h>
#include <string.h>
int main(void){
    FILE *file;
    char index[27];
    char slowo[60];
    file = fopen("polski.txt", "r");
    if(file == NULL){
        perror("nie udało się otworzyć pliku");
        return 1;
    }
    while(feof(file) == 0){
        fscanf(file,"$s", slowo);
        
    }
    srand(time(NULL));
    printf("Podaj slowo, ktore bedzie rozwiazaniem krzyzowki:\n ");
    fgets(slowo, sizeof(slowo)/slowo[0]-1, stdin);
    system('clear');
    return 0;
}