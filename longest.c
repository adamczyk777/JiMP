#include <stdio.h>
#include <string.h>

int main(){
	char slowo[50];
	char najdluzsze[50];
	FILE* file;
	file = fopen("/home/jakub/Downloads/polski.txt", "r");
	if (file == NULL){
		perror("Nie udało sie otworzyc pliku");
		return 1;
	}
	puts("Udało sie otworzyc");
	while(!feof(file)){
		fscanf(file,"%s",slowo);
		if(strlen(slowo) > strlen(najdluzsze)){
			strcpy(najdluzsze, slowo);
		}
	}
	puts(najdluzsze);
}
