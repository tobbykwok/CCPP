#include <stdio.h>
#include <stdlib.h>

int binary_search(int sorted_list[], int low, int high, int element) {
	int mid;
	while(low <= high){
		mid = low + (high - low) /2;
		if(element > sorted_list[mid]) low = mid + 1;
		else if(element < sorted_list[mid]) high = mid - 1;
		else return mid;
	}
	return -1;
}

#define SIZE 10

int main()
{
    int a[SIZE] = {5, 7, 8, 9 , 20, 21, 54, 67, 89, 93};
    int i, e, k, p;
 
    printf("Array: ");
    for(i = 0; i < SIZE; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
 
    printf("\nPlease enter the searched key:");
    scanf("%d",&k);
 
    p = binary_search(a,0,SIZE,k);
 
    if(p >= 0)
    {
        printf("The key %d was found at %d (starting from 0)",k,p);
    }
    else
    {
        printf("The key %d was not found",k);
    }
    return 0;
}
 
