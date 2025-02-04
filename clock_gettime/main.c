#include <stdio.h>
#include <time.h> 

void fun(){
	printf("A fun() iniciou. \n");
	printf("Pressione enter para parar a função. \n");
	while(1)
		if (getchar())
			break;
	
	printf("A função parou \n"); 
} 

int main(){ 
	struct timespec inicio, fim;

	double tempoTotal;
	clock_gettime(CLOCK_MONOTONIC, &inicio);
	fun();
	clock_gettime(CLOCK_MONOTONIC, &fim);
	
	tempoTotal = (fim.tv_sec - inicio.tv_sec); // segundos
	
	tempoTotal += (fim.tv_nsec - inicio.tv_nsec) / 10e9; // nanosegundos	
	
	printf("A função fun() gastou %f segundos. \n", tempoTotal);

	return 0;
}
