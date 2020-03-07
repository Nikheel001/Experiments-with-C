#include<stdio.h>
#include<string.h>
#define lim 50

// array to store solved results
int fiboMemo[lim];

// to count number of times function is called
int fiboFunctionCounter = 0;

// fibonaci decorator to check if value is already calculated
int fetchFibo(int (*func)(int), int* arg);

// basic fibonaci function
int fibo(int x);

// returns stored result
int checkinMemo(int idx);

// store results to array
void saveinMemo(int idx, int val);

void clearFunctionCount(int *arg){
	*arg=0;
}

/* a decorator to increase counter number of times function called.
 * ctr -> reference to function's counter
 * func -> function pointer
 * arg -> args provided to function pointer
 */
int incFuncCtr(int* ctr, int (*func)(int), int* arg);

// simple init
void initMemo(){
	memset(fiboMemo, -1, lim);
	fiboMemo[0]=0;
	fiboMemo[1]=1;
}

int main(){
	initMemo();
	int x = 10;
	do{
		printf("fibo(%d) = %d\n", x, fetchFibo(fibo, &x));
	}while(x--);
	printf("times fibo called %d", fiboFunctionCounter);
	return 0;
}

int incFuncCtr(int* ctr, int (*func)(int), int* arg){
	(*ctr)++;
	printf("---- %d\n", *arg);
	return func(*arg);
}

int fibo(int x){
	int a=x-2,b=x-1;
	return fetchFibo(fibo, &a)+fetchFibo(fibo, &b);
}

int checkinMemo(int idx){
	return fiboMemo[idx];
}

void saveinMemo(int idx, int val){
	fiboMemo[idx]=val;
}

int fetchFibo(int (*func)(int), int *arg){
	int res = checkinMemo(*arg);
	if(res==-1){
		res = incFuncCtr(&fiboFunctionCounter, func, arg);
		saveinMemo(*arg, res);
	}
	return res;
}
