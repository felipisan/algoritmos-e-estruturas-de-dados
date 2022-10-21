int linearSearch(int *vec, int size, int key){
    int i; 
    for (i = 0; i < size; i++){
        if(vec[i] == key)
            return i;
    }
    return -1;
}

//Worst case: O(n)
//Best case: O(1)
//Mem col: O(1)