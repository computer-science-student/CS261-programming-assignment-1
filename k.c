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

		struct student* student1;
		student1 = (struct student *)malloc(sizeof(struct student));
		student1->name = "Jacque";
		student1->points = 40;

	printf("student1 location: %p\n", &student1);
	printf("student1 contents: %p\n", student1);
	printf("student1->name location: %p\n", &(student1->name));
    printf("student1->name contents: %s\n", student1->name);
	printf("student1->points location: %p\n", &(student1->points));
	printf("student1->points contents: %d\n", student1->points);

	add(student1);

	printf("D->data[0]: %p\n", D->data[0]);
	printf("D->data[0]->name contents: %s\n", D->data[0]->name);

//	printf("\nJust after init()\n");
//	printf("D address: %p\n", &D);
//	printf("D contents: %p\n", D);
//	printf("D->size address: %p\n", &(D->size));
//	printf("D->size contents: %d\n", D->size);
//	printf("D->capacity address: %p\n", &(D->capacity));
//	printf("D->capacity contents: %d\n", D->capacity);
//	printf("D->data address: %p\n", &(D->data));
//	printf("D->data contents: %p\n", D->data);
//	printf("D-data[0] address: %p\n", &(D->data[0]));
//	printf("D-data[0] contents: %p\n", D->data[0]);
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

//	test();
	cleanup();
//	disp();
//	free(D);
	return 0;
}


void init(int c) {
	assert(c);
	D->capacity = c;
	D->size = 0;
	D->data = malloc(D->capacity * sizeof(struct student));
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


void delete(int index) {
	assert(index >= 0);
	assert(index < D->size);
	int i;
	for (i=index+1; i<D->size; i++) {
		D->data[i-1] = D->data[i];
	}
	D->size--;
}
*/

void add(void* student1) {
	if (D->size == D->capacity) {
		_resize(D->capacity*2);
	}
	D->data[D->size] = student1;
//	D->size++;
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

/*
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
*/

/*
void disp() {
	int i;
	printf("Array: ");
	for (i=0; i<D->size; i++) {
		printf("%d", D->data[i]->points);
	}
	printf("\n");
	printf("capacity = %d, size = %d\n", D->capacity, D->size);
}
*/

/*
void test() {
	disp();
//		struct student* student1;
		student1 = (struct student *)malloc(sizeof(struct student));
		student1->name = "Jacque";
		student1->points = 40;
	add(student1); disp();
//	add("Bob", 80); disp();
//	add("Katherine", 90); disp();
//	insert(15, 1); disp();
//	insert(25, 3); disp();
//	insert(35, 5); disp();
//	add(70); disp();
//	delete(0); disp();
}
*/
