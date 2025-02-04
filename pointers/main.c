#include <stdio.h>
#include <stdlib.h>

void assignValue(int** array){
	(*array)[5] = 3;
}

void createArray(int** array){
	*array = (void*) malloc(5 * sizeof(int));

	assignValue(array);
}

int main(){
	int* array;

	createArray(&array);

	printf("%d\n", array[5]);

	return 0;
}
