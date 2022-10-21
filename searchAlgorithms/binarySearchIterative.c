int binarySearch(int *vec, int start, int end, int key){
    while(start <= end){
		int center = (int)((start+end)/2);	
        
		if (key == vec[center]) 
			return center;
		if (key < vec[center])
			end = center - 1;
		if (key > vec[center])
			start = center + 1;
	}
	return -1;
}

//Really ugly
//Worst case: O(logn)
//Best case: O(1)
//Mem col: O(1)
