#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Struct for the dynamic array
struct dynArray {
    void** data;
    int size;
    int capacity;
};

// Struct for students.
struct student {
    char* name;
    int points;
};

// make the struct pointer global.
struct dynArray* D;
// Make the array of pointers to students global.
// Just declare it here.
// array_of_pointers is an array with pointers and each of these
// pointers will point to a student struct in the heap.
// Should array_of_pointers be renamed array_of_stu_ptrs?




// Define the function prototypes.
void add(void*); // Is this parameter implemented correctly?
void init(int);
void* get(int);
void set(void*, int); // this one was implemented the same way.
void delete(int);
void _resize(int);
void insert(void*, int); // this one was implemented the same way.
void create_student_pointers(int);
// The bottom ones I haven't modified yet
void cleanup();
void disp();
void test();

// Main function
int main() {
    //printf("This is from dynamic array!");
	D = (struct dynArray *)malloc(sizeof(struct dynArray));
	//printf("46\n");
	assert(D); // checks if the condition is null or not. If null stop program, else continue.
 	init(4); // This is used to create the array
	test();
	cleanup();
	//disp();
	free(D);
	return 0;
}


// Initialize dynamic array. This is like a constructor.
void init(int c) {
    //printf("58\n");
    //assert(c); // Is this assert really needed?
	D->capacity = c;
	D->size = 0;
	D->data = malloc(D->capacity * sizeof(struct student*)); // typecast this later
}

void add(void* student1) { // Is this parameter correctly written?
    //printf("Add function was called here\n");

	if (D->size == D->capacity) {
		_resize(D->capacity*2);
	}
	D->data[D->size] = student1;
	D->size++;
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
	// Check to make sure there are more than 0 students.
	assert(D->size > 0);

	assert(index < D->size);
	int i;
	for (i=index+1; i<D->size; i++) {
		D->data[i-1] = D->data[i];
	}
	D->size--;
}


void _resize(int c) {
	int i;
	void** newdata = malloc(c * sizeof(struct student)); // always typecast malloc
	//printf("108\n");
	assert(newdata);
	D->capacity = c;
	for (i=0; i<D->size; i++) {
		newdata[i] = D->data[i];
	}
	free(D->data);
	D->data = newdata;
}

void insert(void* value, int index) {
    //printf("119\n");
	assert(index >= 0);
	printf("121\n");
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

// Free all the data from the heap.
// Set size and capacity to 0.
void cleanup() {
	assert(D->data);
	free(D->data);

	D->data = NULL;
	D->size = 0;
	D->capacity = 0;
}


void disp() {
    // now the data is a structure of students.
	int i;

	struct student *ptr; // this use to be here

	printf("capacity = \"%d\", size = \"%d\"\n", D->capacity, D->size);

	for (i=0; i< D->size; i++) {
            ptr = D->data[i];
            printf("Student #: %d ", i);
            printf("Student name: \"%s\" and score: \"%d\"\n", ptr->name, ptr->points);

            //printf("Student points: %d\t", ptr->points);
	}
	//printf("hello world\n");
	printf("\n");


	/*    char* name;
    int points;
    */
    //if (D-> size > 0){ // if size is greater than 0
      //  printf("Name: \"%s\" and score: \"%d\"\n", student1->name, student1->points);
    //}
}

void test() {
	disp();

	struct student* student1;
	struct student* student2;
	struct student* student3;

	student1 = (struct student *)malloc(sizeof(struct student));
	student1->name = "Jacque";
	student1->points = 99;

	student2 = (struct student*)malloc(sizeof(struct student));
	student2->name = "Tyler";
	student2->points = 100;

	student3 = (struct student *)malloc(sizeof(struct student));
	student3->name = "Khanh";
	student3->points = 101;

	add(student1); add(student2); add(student3); disp();

	struct student* student4;
	struct student* student5;

	student4 = (struct student *)malloc(sizeof(struct student));
	student4->name = "Kristine";
	student4->points = 33;

	student5 = (struct student *)malloc(sizeof(struct student));
	student5->name = "Jacob";
	student5->points = 0;

	add(student4); disp();
	add(student5); disp();

//	add("Bob", 80); disp();
//	add("Katherine", 90); disp();
//	insert(15, 1); disp();
//	insert(25, 3); disp();
//	insert(35, 5); disp();
//	add(70); disp();
//	delete(0); disp();
}
