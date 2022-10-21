#include <stdio.h>
#include <stdlib.h>

int *bubbleSort(int* vec, int size){
	int i, j;
	int hasSwapped;

	for(i = 0; i < size-1; i++){
		hasSwapped = 0;
		for(j = 0; j < size-1-i; j++){
			if (vec[j] > vec[j+1]){
				int aux = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux;		
				hasSwapped = 1;
			}
		}
		if (hasSwapped == 0)
			break;
	}
	return vec;
}	

//Worst case: O(n²) -> (n²-n)/2
//Best case: O(n)
//Memory Col: O(1)