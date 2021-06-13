#include<stdio.h>
#include<stdlib.h>
//#include<string.h>

int compare_int(const void *x, const void *y) {
	return *((int *)x) - *((int *)y);
}

int compare_char(const void *x, const void *y) {
	return *((char *)x) - *((char *)y);
}

int arr[] = {-3, -2, 0, 9, 12, 34, 44, 56};
char brr[] = {'a', 'a', 'b', 'b', 'd', 'x'};

int main() {
	int len = sizeof(arr) / sizeof(int);

	int to_search = 34;
	int *idx;

	printf("target = %d\n", to_search);

	idx = (int*) bsearch(&to_search, arr, len, sizeof(int), compare_int);
	if (idx != NULL) {
		printf("element found at = %d\n", idx-arr);
	} else {
		printf("element not found ");
	}
	
	for(int i=0;i<len;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	len = sizeof(brr)/sizeof(char);
	char target='z', *src;
	src = (char*) bsearch(&target, brr, len, sizeof(char), compare_char);

	printf("target = %c\n", target);
	if (src != NULL) {
		printf("element found at = %d\n", src-brr);
	} else {
		printf("element not found ");
	}
	
	for(int i=0;i<len;i++){
		printf("%c ", brr[i]);
	}
	
	return 0;
}
