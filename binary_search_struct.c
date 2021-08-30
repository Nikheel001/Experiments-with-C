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

//person *init(char *name, int age, person *x)
//{
//	x = (person *) malloc(sizeof(person));
//	x->name = (char *) malloc(strlen(name)*sizeof(char));
//	x->name = strcpy(x->name, name);
//	x->age = age;
//	return x;
//}

person *init(person *x)
{
	char name[30];
	int age;
	
	x = (person *) malloc(sizeof(person));
	x->name = (char *) malloc(30*sizeof(char));
	
	gets(x->name);
//	fgets(x->name, 30, stdin);
//	scanf("%[^\n]", x->name);
	printf("%s ", x->name);
	
	scanf("%d", &age);
	printf("%d \n", age);
	
	getchar();
	
//	x->name = strcpy(x->name, name);
	x->age = age;
	return x;
}


int main()
{
	person people[5];
	person target;
	person *idx;
	
	printf("look for\n");
	
	target = *init(&target);
	
	int len = sizeof(people)/sizeof(person), i;
	
	printf("\n\ninput list\n");
	
	people[0] = *init(&people[0]);
	people[1] = *init(&people[1]);
	people[2] = *init(&people[2]);
	people[3] = *init(&people[3]);
	people[4] = *init(&people[4]);
	
	printf("\n\nbefore sorting\n");
	
	printf("len = %d\n", len);
	for(i=0;i<len;i++) {
		printf("name = %s, age = %d\n", people[i].name, people[i].age);
	}
	
	qsort(people, len, sizeof(person), compare_person);
	
	printf("\n\nafter sorting\n");
	
	printf("len = %d\n", len);
	for(i=0;i<len;i++) {
		printf("name = %s, age = %d\n", people[i].name, people[i].age);
	}
	
	idx = (person*) bsearch(&target, people, len, sizeof(person), compare_person);
	
	if(idx!=NULL){
		printf("\n\nFOUND name = %s, age = %d\n", idx->name, idx->age);
	}else{
		printf("\n\nNOT FOUND");
	}
	
	return 0;
}
