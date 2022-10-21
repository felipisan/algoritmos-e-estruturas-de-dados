//Ok this is pretty dumb don't use this. This is majorly for studies purposes.

int linearSearch(int *vec, int size, int key){
    int i;
    size--;
 
    if (size >= 0) {
        if (vec[size] == key)
            return size;
        else
            i = linearSearch(vec, size, key);
    }
    else
        return -1;
    return i;
}
 
}


//Worst case: O(n)
//Best case: O(1)
//Mem col: O(1)