#include <stdio.h>
#include <stdlib.h>



void intercalate(float *vector, int start, int center, int end){
	float* vectorAux = (float *) malloc(sizeof(int) * (end - start) + 1);

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

void mergeSort(float* vector, int start, int end){
	if (end <= start) 
		return;

	int center = (int)((start + end) / 2.0);
	mergeSort(vector, start, center);
	mergeSort(vector, center+1, end);

	intercalate(vector, start, center, end);
}

int main() {
    int n, m, b;

    scanf("%d %d %d", &n, &m, &b);
    float *ar = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) 
        scanf("%f", &ar[i]);

    mergeSort(ar, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%.2f ", ar[i]);
    return 0;
}