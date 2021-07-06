#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct student{
	char* name;
	int points;
};


struct dynArray {
	int size;
	int capacity;
	void** data;
};


struct dynArray* D;

void add(void*);
void* get(int);
void set(void*, int);
void insert(void*, int);
void delete(int);
void init(int);
void cleanup();
void _resize(int);
void test();
void disp();


int main() {
	D = malloc(sizeof(struct dynArray));
	assert(D);
 	init(4);

//	putchar('\n');
//	printf("student1 location: %p\n", &student1);
//	printf("student1 contents: %p\n", student1);
//	printf("student1->name location: %p\n", &(student1->name));
//      printf("student1->name contents: %s\n", student1->name);	
//	printf("student1->points location: %p\n", &(student1->points));
//	printf("student1->points contents: %d\n", student1->points);

//	add(student1);

//	struct student *ptr;
//	ptr = D->data[0];	

//	putchar('\n');
//	printf("D->data[0]: %p\n", D->data[0]);
//	printf("ptr contents: %p\n", ptr);
//	printf("ptr->name address: %p\n", &(ptr->name));
//	printf("ptr->name contents: %s\n", ptr->name);
//	printf("ptr->points address: %p\n", &(ptr->points));
//	printf("ptr->points contents: %d\n", ptr->points);
//	putchar('\n');

//	printf("D->data[0]): %d\n", *(D->data[0]));
//	printf("D->data[0]->name contents: %s\n", D->data[0]->name);

//	printf("\nJust after add()\n");
//	printf("D address: %p\n", &D);
//	printf("D contents: %p\n", D);
//	printf("D->size address: %p\n", &(D->size));
//	printf("D->size contents: %d\n", D->size);
//	printf("D->capacity address: %p\n", &(D->capacity));
//	printf("D->capacity contents: %d\n", D->capacity);
//	printf("D->data address: %p\n", &(D->data));
//	printf("D->data contents: %p\n", D->data);
//	printf("D->data[0] address: %p\n", &(D->data[0]));
//	printf("D->data[0] contents: %p\n", D->data[0]);
//	printf("D->data[0]->points: %d\n", (D->data[0]).points);
//	printf("D->data[1] address: %p\n", &(D->data[1]));
//	printf("D->data[1] contents: %p\n", D->data[1]);
	
//	printf("\nNow running add()\n");
//	add(); 
//	printf("D->data[0] address: %p\n", &(D->data[0]));
//	printf("D->data[0] contents: %p\n", D->data[0]);
//	printf("D->data[0]->points address %d\n", D->data[0]->points);
//	printf("D->data[1] address: %p\n", &(D->data[1]));
//	printf("D->data[1] contents: %p\n", D->data[1]);
//	putchar('\n');

	test();
	cleanup();
//	disp();
//	free(D);
	return 0;
}


void init(int c) {
	assert(c);
	D->capacity = c;
	D->size = 0;
	D->data = malloc(D->capacity * sizeof(struct student*));
}


void cleanup() {
	assert(D->data);
	free(D->data);
	D->data = NULL;
	D->size = 0;
	D->capacity = 0;
}

/*
void* get(int index) {
	assert(index >= 0);
	assert(index < D->size);
	return D->data[index];
}


void set(void* value, int index) {
	assert(index >= 0);
	assert(index < D->size);
	D->data[index] = value;
}
*/

void delete(int index) {
	assert(index >= 0);
	assert(index < D->size);
	int i;
	for (i=index+1; i<D->size; i++) {
		D->data[i-1] = D->data[i];
	}
	D->size--;
}


void add(void* record) {
	if (D->size == D->capacity) {
		_resize(D->capacity*2);
	}	
	D->data[D->size] = record;
	D->size++;
}


void _resize(int c) {
	int i;
	void** newdata = malloc(c * sizeof(struct student));
	assert(newdata);
	D->capacity = c;
	for (i=0; i<D->size; i++) {
		newdata[i] = D->data[i];
	}
	free(D->data);
	D->data = newdata;
}


void insert(void* value, int index) {
	assert(index >= 0);
	assert(index < D->size);

	int i;
	if (D->size == D->capacity) {
		_resize(D->capacity*2);
	}
	for (i=D->size; i>index; i--) {
		D->data[i] = D->data[i-1];
	}
	D->data[index] = value;
	D->size++;
}


void disp() {
	int i;

	struct student *ptr;
	
	putchar('\n');
	printf("capacity: %d\n", D->capacity);
	printf("size: %d\n", D->size);
	for (i=0; i<D->size; i++) {
		ptr = D->data[i];		
		printf("Student %d: ", i);
		printf("%s, ", ptr->name);
		printf("%d\n", ptr->points);
	}
	putchar('\n');
}


void test() {
	struct student* student1;
	struct student* student2;
	struct student* student3;
	struct student* student4;
	struct student* student5;
	struct student* student6;
	struct student* student7;
	struct student* student8;
	struct student* student9;

	student1 = (struct student *)malloc(sizeof(struct student));
	student1->name = "Jacque";
	student1->points = 40;

	student2 = (struct student*)malloc(sizeof(struct student));
	student2->name = "Tyler";
	student2->points = 100;

	student3 = (struct student *)malloc(sizeof(struct student));
	student3->name = "Khanh";
	student3->points = 99;
	
	student4 = (struct student *)malloc(sizeof(struct student));
	student4->name = "Kristine";
	student4->points = 33;

	student5 = (struct student *)malloc(sizeof(struct student));
	student5->name = "Jacob";
	student5->points = 0;

	student6 = (struct student *)malloc(sizeof(struct student));
	student6->name = "Trent";
	student6->points = 295;
	
	student7 = (struct student *)malloc(sizeof(struct student));
	student7->name = "Xi";
	student7->points = 55;	
	
	student8 = (struct student *)malloc(sizeof(struct student));
	student8->name = "Bill";
	student8->points = 1;

	student9 = (struct student *)malloc(sizeof(struct student));
	student9->name = "Sarah";
	student9->points = 15;
	

	disp();
	add(student1); add(student2); add(student3); disp();
	add(student4); disp();
	add(student5); disp();
	insert(student6, 1); disp();
	insert(student7, 3); disp();
	insert(student8, 5); insert(student9, 2); disp();
	delete(0); disp();
}

