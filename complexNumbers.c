#include <stdio.h>
#include <math.h>
// to add math when compiling add -lm
char exponential(struct complex);
void printExponential(struct complex compl);
int main(void){
	struct complex{
		int r; //real
		int i; //imaginary
	};
	struct complex compl1 = {5,5};
	struct complex compl2 = {4,4};
	return 0;
}
int exponential(struct complex compl){
	
}
void printExponential(struct complex compl){
	printf("%d", compl.r);
	printf("%+d", compl.i);
}
