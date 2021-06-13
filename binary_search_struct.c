#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct p {
	int age;
	char *name;
} person;

int compare_person(const void *x, const void *y)
{
	person *p1,*p2;
	p1 = (person *)x;
	p2 = (person *)y;
	
	int nm = strcmp(p1->name, p2->name);
	if(nm == 0){
		return p1->age-p2->age;
	}
	return nm;
}

person *init(char *name, int age, person *x)
{
	x = (person *) malloc(sizeof(person));
	x->name = (char *) malloc(strlen(name)*sizeof(char));
	x->name = strcpy(x->name, name);
	x->age = age;
	return x;
}

int main()
{
	person people[5];
	person target, *idx;
	target = *init("anil", 23, &target);
	
	int len = sizeof(people)/sizeof(person), i;
	
	people[3] = *init("nikheel", 23, &people[3]);
	people[2] = *init("anil", 21, &people[2]);
	people[4] = *init("sachin", 23, &people[4]);
	people[0] = *init("abcd", 10, &people[0]);
	people[1] = *init("abcd", 12, &people[1]);
	
	idx = (person*) bsearch(&target, people, len, sizeof(person), compare_person);
	
	printf("len = %d\n", len);
	for(i=0;i<len;i++) {
		printf("name = %s, age = %d\n", people[i].name, people[i].age);
	}
	
	if(idx!=NULL){
		printf("FOUND name = %s, age = %d\n", idx->name, idx->age);
	}else{
		printf("NOT FOUND");
	}
	
	return 0;
}
