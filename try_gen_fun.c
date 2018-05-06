#include<stdio.h>
#include<string.h>

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

void try_gen_function(void *ptr,char abc[])
{
	if(strcmp(abc,"char")==0)
	{
		printf("%c\n",*(char *)ptr);
	}
	else if(strcmp(abc,"int")==0)
	{
		printf("%d\n",*(int *)ptr);
	}
	else if(strcmp(abc,"struct node")==0)
	{
		printf("%d\n",(*(struct node *)ptr).abc);
	}
	else if(strcmp(abc,"struct any")==0)
	{
		printf("%d\n",(*(struct any *)ptr).id);
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
  
	printf("%d\t",var1.id);
	printf("%d\t",var2.id);
	printf("%d\n",var2.id);
	printf("%c\t",*(char *)var1.ptr);
	printf("%d\n",*(int *)var2.ptr);
	printf("%d\n",(*(struct node *)var3.ptr).abc);
	printf("%d\n",*(int *)xyz);
  
	// IMPORTANT execution below..
  
	try_gen_function(&abc,"char");
	try_gen_function(&b,"int");
	try_gen_function(&v1,"struct node");
  try_gen_function(&v1,"struct any");
}
