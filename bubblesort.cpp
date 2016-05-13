#include<iostream>

void bubbleSort(int* arr, int n){
	bool swapped = true;
	int j = 0;
	int tmp;
	while(swapped){
		swapped = false;
		j++;
		for(int i = 0;i< n-j;i++){
			if(arr[i] > arr[i+1]){
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				swapped = true;
			}
		}
	}
}
int main(){
	int a[] = {3,4,1,2,8,54,23,12,49};
	int N = sizeof(a)/sizeof(int);
	bubbleSort(a, N);
	for(int i = 0;i < N; i++){
		printf("%d\r\n", a[i]);
	}
	return 0;
}
