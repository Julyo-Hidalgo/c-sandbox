#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void merge(int* v, int left, int middle, int right){
	int size = right - left + 1;

	int part1 = left; 
	int part2 = middle + 1; 
	int is_part1_finished = 0;
	int is_part2_finished = 0;
	int *temp;
	temp = (int *) malloc(size * sizeof(int));
	
	if (temp != NULL){
		for (int i = 0; i < size; i++){
			if (!is_part1_finished && !is_part2_finished){
				if (v[part1] < v[part2]){
					temp[i] = v[part1];
					part1++;
				}else{
					temp[i] = v[part2];
					part2++;
				}
				
				if (part1 > middle)
					is_part1_finished = 1;

				if (part2 > right)
					is_part2_finished = 1;
			}else{
				if (!is_part1_finished){
					temp[i] = v[part1]; 
					part1++;
				}else{
					temp[i] = v[part2]; 
					part2++;
				}	
			}	
		}
	
		int i, j;	
		for (i = 0, j = left; i < size; i++, j++){
			v[j] = temp[i];
		}
	}

	free(temp);
}


void mergeSort(int* v, int left, int right){
	int middle;
	
	if (left < right){
		middle = floor((left+right)/2);
		mergeSort(v, left, middle);
		mergeSort(v, middle + 1, right);

		merge(v, left, middle, right);
	}

}


int main(){
	int vector[6] = {1, 22, 3, 20, 9, 10};

	for (int i = 0; i < 6; i++)
		printf("%d, ", vector[i]);	

	printf("\n");
		
	mergeSort(vector, 0, 5);	

	for (int i = 0; i < 6; i++)
		printf("%d, ", vector[i]);	

	printf("\n");
	
	return 0;
}
