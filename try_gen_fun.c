#include<stdio.h>

struct any
{
	int id; // anything can be here or this is not required at all.
	void *ptr;
}; // Maybe that's how 'any' datatype is created.

struct node
{
	int abc;
	struct node *next;
};

enum types {
	Int,Char,Node,Any
};

void try_gen_function(void *ptr,enum types x)
{
	switch(x){
		case Char:
			printf("%c\n",*(char *)ptr);
			break;
		case Int:
			printf("%d\n",*(int *)ptr);
			break;
		case Node:
			printf("%d\n",(*(struct node *)ptr).abc);
			break;
		case Any:
			printf("%d\n",(*(struct any *)ptr).id);	
			break;
		default:
			break;
	}
}

void main()
{
	struct any var1,var2,var3;
	struct node v1,v2;
	v1.next=&v2;
	v1.abc=10;
	v2.abc=5;
	void *xyz=&v1.abc;
	char abc='a';
	int b=4;
	
	var1.id=1;
	var1.ptr = &abc;
	var2.id=2;
	var2.ptr = &b;
	var3.id=3;
	var3.ptr=&v1;
  
	// trying without function...
  
//	printf("%d\t",var1.id);
//	printf("%d\t",var2.id);
//	printf("%d\n",var2.id);
//	printf("%c\t",*(char *)var1.ptr);
//	printf("%d\n",*(int *)var2.ptr);
//	printf("%d\n",(*(struct node *)var3.ptr).abc);
//	printf("%d\n",*(int *)xyz);
  
	// IMPORTANT execution below..
	enum types t1;
	t1=Any;
	try_gen_function(&v1, t1);
	
	t1=Node;
	try_gen_function(&v1,t1);
	
	// Any and Node has some similarity :)
	
	t1=Char;
	try_gen_function(&abc,t1);
	t1=Int;
	try_gen_function(&b,t1);
}
