#include <stdio.h>
#include <stdlib.h>

int* insertionSort(int* vec, int size){
	int j; 
	for(j = 1; j < size; j++){
		int key = vec[j];
		int i = j - 1; 
		
		while (i >= 0 && vec[i] > key){ 
			vec[i + 1] = vec[i]; 
			i--;
		}
		vec[i + 1] = key;
	}
	return vec;
}