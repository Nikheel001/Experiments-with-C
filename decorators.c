#include<stdio.h>

void printStar(){
	printf("********\n");
}

/*
Decorator in C
*/
void starDecor(void (*func)(char*), char * arg){
	/*
	Do anything before function execution
	*/
	printStar();
	func(arg);
	/*
	Do anything after function execution
	*/
	printStar();
}

void welcome(char* name){
	printf("welcome %s\n",name);
}

int main(){
	starDecor(welcome, "Headshot");
	return 0;
}
