#include <stdio.h>
#include <string.h>
int main(){
	FILE *file;
	int iter;
	char slowo[50];
	char slowa[10][50];
	file = fopen("/home/jakub/Downloads/polski.txt", "r");
	if (file == NULL){
		perror("Nie udało sie otworzyc pliku");
		return 1;
	}
	for(iter = 0; iter<=9; iter++){
		fscanf(file,"%s", slowo);
		strcpy(slowa[iter], slowo);
		puts(slowa[iter]);
	}
	return 0;
}


