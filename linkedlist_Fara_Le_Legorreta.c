// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node{//Node of a doubly linked list
    struct Node* next;
    int data;
    struct Node* prev;
};

//declare global value
struct Node* head;
struct Node* tail;

void insert(struct Node*, struct Node*);
void delete(struct Node*, struct Node*, struct Node*);
void _insert1(struct Node*);
void _insert2(struct Node*, struct Node*);
void _insert3(struct Node*, struct Node*, struct Node*);
void _delete1();
void _delete2(struct Node*, struct Node*); // I got rid of one of these parameters.
//void _delete3(struct Node*, struct Node*);
void init();
void cleanup();
void disp();
void test();

int main(){
    init();
    test();
    cleanup();
    return 0;
}

void init(){ //create 2 pointers to start the doubly linked list
    printf("init func called\n");
    head= tail = NULL;
}

void cleanup(){
    printf("clean func called\n");
     struct Node* curr = head;
    while(curr != NULL){//as long as the list doesn't ends
        curr = curr->next;
        free(curr);//move on to the next node
    }
}

void _insert1(struct Node* curr){//insert node at the front
        if(head == NULL){//if there is no node at the linked list yet
        printf("insert 1 no node called\n");
            curr->next = NULL;
            head =curr;
            tail =curr;
            //printf("Seg fault check\n");
        }
        else{//if the doubly linked list already have existing mode
            printf("insert 1 node exist called\n");
           head->prev = curr;//head is pointing to the adjc node so maje prev of adjc node points to curr
           head = curr;

        }
}

void _insert2(struct Node* curr, struct Node *pred){//adjc is the node next to current node
    if(tail == pred){//if added at the end of the list
      printf("insert 2 end called\n");//insert after
     // curr->next = pred->next; // I commented this out because curr->next = NULL;
     pred->next = curr;
     curr->prev = pred;
     curr->next = NULL; // set the next to be NULL
     tail = curr;
      //tail->next= curr;
      //curr->prev= tail;
    }
    else{//if insert at middle
    printf("Insert 2 mid called here\n");//append
      curr->next = pred->next; //make next of current point to the same place as previous node
      //connect the pointers of curr and pred node together
      pred->next = curr;
      curr->prev = pred;
      //make connect from the node adjacent and the current node
      curr->next->prev= curr;

    }
}

void insert(struct Node* curr, struct Node* pred){
  if(pred == NULL){
  _insert1(curr);
  }
  else{
  _insert2(curr, pred);
  }
}

void _delete1(){//delete first node
  struct Node* curr = head; //create a node pointer pointing to the 1st node of the list
  // Create a node pointer pointing to the 2nd node of the list.

  // Check to make sure that there are ANY nodes at all.
  //printf("Deleting: %d\n", curr->data);
  if (head == NULL){
    printf("The linked list doesn't have nodes.\n");
    return;
  }

  struct Node* next = curr->next;
  //printf();


  if(curr->next == NULL){//if there is only 1 node
  printf("Delete func for only 1 node called\n");
    head = tail = NULL; //reset to inital condition
  }
  else{//more than 1. Delete first node
    printf("Delete func for more than 1 node called\n");
    // make the second node in the list have a previous val of null

    //head = curr->next; //make the head pointer point to the same place as the next pointer of the delete node
    head = next; // I am not sure why this doesn't work. It deletes the whole tree
    // set next node to be the null
    next->prev = NULL;

  }
  free(curr);//delete the node.
}

void _delete2(struct Node* curr, struct Node* adjc){//delete at middle
    // get pred
    //struct Node* pred = curr->prev;


    pred->next = adjc->prev; //make the next of previous node points to the same place as the deletemed node
    adjc->prev = curr->next; //make the prev of the node next to the delete node points to the node preiouvs to delete node
    free(curr);
}
/*
void _delete3(struct Node* curr, struct Node* pred){//delete at end
    pred->next = NULL;
    tail = pred->prev; //make tail point to previous node
    free(curr);
}*/

void delete(struct Node* curr, struct Node* pred, struct Node* adjc){
    if( pred == NULL){//node at head
        _delete1();
     }
     else if( curr->next == NULL){//node at end
        _delete3(curr, pred);
     }
     else{
        _delete2(curr, pred, adjc);//node at middle
     }
}

void disp(){
    struct Node* curr = head;
    while(curr != NULL){//as long as the list doesn't ends
        printf("%d\t", curr->data);
        curr = curr->next; //move on to the next node
    }
    printf("\n");
}

void test(){

    //create the first node
    struct Node* n1 = malloc(sizeof(struct Node));
    //create Node n1
    n1->data = 10;
    n1->next = NULL;
    n1->prev = NULL;
    insert(n1, NULL);
    disp();
    //delete(n1, NULL, NULL);
    //disp();
    // init 2nd node
   struct Node* n2 = malloc(sizeof(struct Node));
    n2->data = 20;
    n2->next = NULL;
    n1->prev = NULL;
    insert(n2, n1);
    disp();
//init 3rd node
    struct Node* n3 = malloc(sizeof(struct Node));
    n3->data = 30;
    n3->next = NULL;
    n3->prev = NULL;
    insert(n3, n2);
    disp();
//init 4th node
    struct Node* n4 = malloc(sizeof(struct Node));
     n4->data = 25;
     n4->next = NULL;
     n4->prev = NULL;
    insert(n4, n2);
    disp();
//init 5th node
    struct Node* n5 = malloc(sizeof(struct Node));
    n5->data = 40;
    n5->next = NULL;
    n5->prev = NULL;
    insert(n5, n3);
    disp();
    //delete(n1, NULL); disp();
    _delete1(); disp();
    _delete1(); disp();
    _delete1(); disp();
    _delete1(); disp();
    _delete1(); disp();
    _delete1(); disp();

}
