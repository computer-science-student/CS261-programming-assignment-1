/*
    Insert programmer names and id here for credit.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Struct for students.
struct student{
	char* name;
	int points;
};

// Struct for the dynamic array
struct dynArray {
	int size;
	int capacity;
	// The data pointer pointer will
	// be an array with pointers. Each
	// of those pointers will point to
	// a different student structure,
	// which is stored in the heap.
	void** data;
};

// Define global struct pointer
// for the dynamic array.
struct dynArray* D;

// Function prototypes.
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
	// Assert functions check if the condition is null or
	// not, false or not. If the condition is null or false,
	// the program terminates with error message. If the
	// conditional is not null or false, the program continues.
	assert(D);
 	init(4); // Init is used to create the array.
	test();
	cleanup();
	disp();
	free(D);

	return 0;
}
// Initialize dynamic array. This is like a constructor.
void init(int c) {
	assert(c);
	D->capacity = c;
	D->size = 0;
	// Does this malloc need to be typecasted?
	D->data = malloc(D->capacity * sizeof(struct student*));
}


void cleanup() {
	assert(D->data);
	free(D->data);
	D->data = NULL;
	D->size = 0;
	D->capacity = 0;
}


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
	struct student* student10;
	struct student* ptr;

	student1 = (struct student *)malloc(sizeof(struct student));
	student1->name = "JACQUE";
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

	student10 = (struct student *)malloc(sizeof(struct student));
	student10->name = "Teresa";
	student10->points = 92;

	putchar('\n');
	disp();
	add(student1); add(student2); add(student3); disp();
	set(student10, 0);
	add(student4); disp();
	add(student5); disp();
	insert(student6, 1); disp();
	insert(student7, 3); disp();
	insert(student8, 5); insert(student9, 2); disp();
	delete(0); disp();
	ptr = get(0);
		printf("Get results: %p\n", ptr);
		printf("Get name: %s\n", ptr->name);
		printf("Get points: %d\n", ptr->points);
	putchar('\n');

	free(student1);
	free(student2);
	free(student3);
	free(student4);
	free(student5);
	free(student6);
	free(student7);
	free(student8);
	free(student9);
	free(student10);
}

