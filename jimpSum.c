#include <stdio.h>
int arraySum(int array[], int arrLength);
void main(void){
  int array1[]={1,2};
  int array2[]={1,2,3};
  printf("%d\n",arraySum(array1, sizeof(array1)/sizeof(array1[0])));
  printf("%d\n",arraySum(array2, sizeof(array2)/sizeof(array2[0])));
}
int arraySum(int array[], int arrLength){
  int sum;
  int i;
  for(i = 0;i < arrLength; i++){
    sum += array[i];
  }
  return sum;
}
