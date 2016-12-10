#include <stdio.h>
int square(int num1);
int main(void){
	int provided;
	int result;
	printf("Wprowadz liczbe wyrazow dla jakich chcesz policzyc sume ciagu kwadratow: ");
	scanf("%d", &provided);
	result =  square(provided);
	printf("nasza liczba to: %d", result);
}
int square(int num1){
	int result = num1*(num1 + 1)*(2*num1 + 1)/6;
	return result;
}
