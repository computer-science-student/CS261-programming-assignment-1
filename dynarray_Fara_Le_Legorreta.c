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
struct student* array_of_pointers[];
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
	printf("46\n");
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
    printf("58\n");
    //assert(c); // Is this assert really needed?
	D->capacity = c;
	D->size = 0;
	D->data = malloc(D->capacity * sizeof(struct student*));
}

struct student *student1; // a student is a pointer

void add(void* student1) { // Is this parameter correctly written?
    printf("Add function was called here\n");

	if (D->size == D->capacity) {
		_resize(D->capacity*2);
	}
	D->data[D->size] = student1;
	D->size++;
}

void* get(int index) {
    printf("77\n");
	assert(index >= 0);
	printf("79\n");
	assert(index < D->size);
	return D->data[index];
}

void set(void* value, int index) {
    printf("85\n");
	assert(index >= 0);
	printf("87\n");
	assert(index < D->size);
	D->data[index] = value;
}

void delete(int index) {
    printf("93\n");
	assert(index >= 0);
	printf("95\n");
	assert(index < D->size);
	int i;
	for (i=index+1; i<D->size; i++) {
		D->data[i-1] = D->data[i];
	}
	D->size--;
}


void _resize(int c) {
	int i;
	int* newdata = (int *)malloc(c * sizeof(int)); // always typecast malloc
	printf("108\n");
	assert(newdata);
	D->capacity = c;
	for (i=0; i<D->size; i++) {
		newdata[i] = D->data[i];
	}
	free(D->data);
	D->data = newdata;
}

void insert(void* value, int index) {
    printf("119\n");
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
    printf("137\n");
	assert(D->data);
	free(D->data);
	D->data = NULL;
	D->size = 0;
	D->capacity = 0;
}

void disp() {
    // now the data is a structure of students.
	int i;
    struct student *ptr;
    printf("%d\n", D->size);
	for (i=0; i< D->size; i++) {
            printf("hello world 1\n");
            ptr = D->data[i];
            printf("Student points: %d\t", ptr->points);
	}
	printf("hello world\n");
	printf("\n");
	printf("capacity = %d, size = %d\n", D->capacity, D->size);

	/*    char* name;
    int points;
    */
    printf("Name: %s and score: %p", student1->name, student1->points);
}

void create_student_pointers(int c){
    // This function creates an array of student pointers.
    // The array is of size c.
    // Should I put this in the heap?
    // D = malloc(sizeof(struct dynArray));
    //struct student* student_pointers[D->capacity]; // student pointers have same capacity as D.

    // Create three students
    struct student student2;
    struct student student3;

    //student_pointer[0] = &a_student;

    for (int i=0; i <D->capacity; i++) {
        // put the student pointers in.
        //printf("index: %d\n", i);
        // initalize the student.
        //student_pointers[i] = array_of_pointers[i]; // set to regular student?

    }

}


void test() {
	//disp();
	// The parameters to add should be void*.
	// type arrayName [ arraySize ];
	//create_student_pointers(D->capacity); // commented this out because not sure what it is for.

    // Add the data for this student!
    student1 = (struct student *)malloc(sizeof(struct student)); // free this later.
    student1->name = "Name";
    student1->points = 10;
    printf("Before add\n");
    add(student1);
    printf("After add\n");

    disp();


	//add(); add(); add(); disp();
/*	add(40); disp();
	add(50); add(60);
	insert(15, 1); disp();
	insert(25, 3); disp();
	insert(35, 5); disp();
	add(70); disp();*/
	delete(0); //disp();
}
