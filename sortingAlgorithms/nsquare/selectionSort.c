//The worst 'serious' sorting algorithm there is. Please do not use this. 
//Ever. It's not even stable. 
//Actually, if you ever manage to use a code that requires you to linearly
//search for the greater or smallest key in an array AND AT THE SAME TIME
//need to sort that, this might become useful. I used it once on a program
//that kept a library of wines in C.

void selectionSort(int *vec, int n){
    int i, j, lowest_idx;
 
    for (i = 0; i < n-1; i++){
        lowest_idx = i;
        for (j = i + 1; j < n; j++)
          if (vec[j] < vec[lowest_idx])
            lowest_idx = j;

           if(lowest_idx != i)
            swap(&vec[lowest_idx], &vec[i]);
    }
}