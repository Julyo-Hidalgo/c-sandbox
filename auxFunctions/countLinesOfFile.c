#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_DIGITS 11 //Maximum digit lenght of type int, including EOF 

int countLinesOfFile(FILE* file, int maxLineLenght){
	int linesNumber = 0;
	char string[maxLineLenght];

	while(fgets(string, maxLineLenght, file) != NULL){
		linesNumber++;	
	}

	return linesNumber;
}

int main(){
	char filePath[PATH_MAX];
	printf("Type the file path: ");
	scanf("%s", filePath);

	FILE* filePointer = fopen(filePath, "r");

	int linesNumber = countLinesOfFile(filePointer, MAX_DIGITS);

	printf("%d\n", linesNumber);

	fclose(filePointer);
}
