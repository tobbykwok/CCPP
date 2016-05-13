#define VAL_SWITCH_TO_INSERTIONSORT_LENGTH 100

int partation_lo(int* arr, int lo , int hi){
	int i = lo, j = hi + 1;
	int base = arr[lo];
	while(1){
		while(base > arr[++i]){
			if(i == hi) break;
		}
		while(base < arr[--j]){
			if(j == lo) break;
		}
		if(i >= j){
			break;
		}
		swap(arr, i, j);
	}
	swap(arr, j ,lo);
	return j;
}

int partation_hi(int* arr, int lo , int hi){
	int i = lo - 1, j = hi;
	int base = arr[hi];
	while(1){
		while(base > arr[++i]){
			if(i == hi) break;
		}
		while(base < arr[--j]){
			if(j == lo) break;
		}
		if(i >= j){
			break;
		}
		swap(arr, i, j);
	}
	swap(arr, i ,hi);
	return i;
}

void quicksort(int* arr, int s, int e){
	if(e<=s){
		return;
	}
	int a = partation_hi(arr, s, e);
	quicksort(arr, s, a-1);
	quicksort(arr, a+1, e);
}

void quicksort_fast(int* arr, int s, int e){
	if(e <= s + VAL_SWITCH_TO_INSERTIONSORT_LENGTH){
		InsertionSort_Range(arr, s, e);
	}
	int a = partation_hi(arr, s, e);
	quicksort(arr, s, a-1);
	quicksort(arr, a+1, e);
}
