#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *x, const void *y){
	return *((int *)x) - *((int *)y);
}

int compare_char(const void *x, const void *y){
	return *((char *)x) - *((char *)y);
}

int main()
{
	
	int arr[] = {-3,56,12,44,-2,9,0,34};
	int len = sizeof(arr)/sizeof(int);
	
	qsort(arr, len, sizeof(int), compare_int);
	
	printf("len = %d\n", len);
	for(int i=0;i<len;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	char brr[] = {'d', 'b', 'a', 'x', 'a', 'b'};
	len = sizeof(brr)/sizeof(char);
		
	qsort(brr, len, sizeof(char), compare_char);
	
	printf("len = %d\n", len);
	for(int i=0;i<len;i++){
		printf("%c ", brr[i]);
	}
	
	return 0;
	
}
