#include <stdio.h>
#include <time.h>

int func(){
	printf("Press Enter to get out of func: ");
	while (1){
		if(getchar()){
			break;	
		}
	}
}

int main(){
	struct timespec start, end;	

	clock_gettime(CLOCK_MONOTONIC, &start);
	func();	
	clock_gettime(CLOCK_MONOTONIC, &end);

	double totalTime = end.tv_sec - start.tv_sec;
	totalTime += (end.tv_nsec - start.tv_nsec) / 10e9;

	printf("Total time of func execution: %lf\n", totalTime);
}
