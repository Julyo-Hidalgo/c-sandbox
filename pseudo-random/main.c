#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int number = rand();
	
	srand(1);	
	printf("Time: %d\n", time(NULL));
	printf("The PRNumber is: %d\n", number);

	srand(time(NULL));	
	number = rand();

	time_t curtime;
	time(&curtime);
	printf("Time: %s", ctime(&curtime));
	printf("The PRNumber is: %d\n", number);
}
