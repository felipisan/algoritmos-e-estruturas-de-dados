int binarySearch(int *vec, int start, int end, int key){
    int center = (int) (start + end)/2;
    
    if (key == center)
        return center;
    if (start > end)
        return -1;
    if (key < vec[center])
        return binarySearch(vec, start, center - 1, key);
    if (key > vec[center])
        return binarySearch(vec, center + 1, end, key);
}

//Worst case: O(logn)
//Best case: O(1)
//Mem col: O(n) except nobody cares
