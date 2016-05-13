void InsertionSort(int* arr, int N){
	InsertionSort_Range(arr, 0, N - 1);
}

void InsertionSort_Range(int* arr, int s, int e){
	int i = s, j = s;
	int last, offset;
	for(; i < e; i++){
		last = arr[i];
		offset = i;
		for(j = i + 1; j <= e; j++){
			if(arr[j] < last){
				last = arr[j];
				offset = j;
			}
		}
		swap(arr, i, offset);
	}
}
