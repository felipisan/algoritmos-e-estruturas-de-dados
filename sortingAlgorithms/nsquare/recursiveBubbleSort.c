#include <stdio.h>
#include <stdlib.h>

int *bubbleSort(int* vec, int size, int i){
	if (i >= size - 1) //Base case
        return vec;

	int j;
    int hasSwapped;
    for (j = 0; j < size - 1 - i; j++){
        hasSwapped = 0;
        if (vec[j] > vec[j + 1]){
            int aux = vec[j];
            vec[j] = vec[j + 1];
            vec[j + 1] = aux;
            hasSwapped = 1;
        }
        if(hasSwapped == 0)
            return vec;
    }
}	

//Worst case: O(n²) -> (n² + n - 2)/2
//Best case: O(n)
//Memory col: O(n)