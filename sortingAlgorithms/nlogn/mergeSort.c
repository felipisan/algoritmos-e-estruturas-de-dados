#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* vector, int start, int end){
	if (end <= start) 
		return;

	int center = (int)((start + end) / 2.0);
	mergeSort(vector, start, center);
	mergeSort(vector, center+1, end);

	intercalate(vector, start, center, end);
}

void intercalate(int *vector, int start, int center, int end){
	int* vectorAux = (int*) malloc(sizeof(int) * (end - start) + 1);

	int i = start;
	int j = center + 1;
	int k = 0;

	while(i <= center && j <= end){
		if (vector[i] <= vector[j]){
			vectorAux[k] = vector[i];
			i++;
		}
		else{
			vectorAux[k] = vector[j];
			j++;
		}
		k++;
	}

	while(i <= center){
		vectorAux[k] = vector[i];
		i++;
		k++;
	}

	while(j <= end){
		vectorAux[k] = vector[j];
		j++;
		k++;
	}

	for(i = start, k = 0; i <= end; i++,k++)
		vector[i] = vectorAux[k];
	free(vectorAux);
}

//Worst case: O(nlog n) ->  4nlog2(n) + 5n - 4 
//Best case: O(nlog n)
//Mem col: 0(n)