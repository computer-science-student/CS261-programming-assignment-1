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

void insert(struct Node*, struct Node*, struct Node*);
void delete(struct Node*, struct Node*, struct Node*);
void _insert1(struct Node*);
void _insert2(struct Node*, struct Node*, struct Node*);
void _delete1();
void _delete2(struct Node*, struct Node*, struct Node*);
void _delete3(struct Node*, struct Node*);
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
    head= tail = NULL;
}

void cleanup(){
    struct Node* curr;//create a curr pointer to go thru all the node in the doubly linked list
    while(head != NULL){
        curr->prev = head; // assign the temp pointer to the prev pointer first node
        curr = curr->next;
        free(curr);
    }
}

void _insert1(struct Node* curr){//insert node at the front
        if(head == NULL){//if there is no node at the linked list yet
            curr->next = NULL; //make sure the end of the added node is NULL
            curr->next = NULL;
            head = tail = curr->prev ;
        }
        else{//if the doubly linked list already have existing mode
            curr->prev = NULL;
            head = curr->prev;
        }
}
// I MIGHT CUT DOWN INSERT FRONT, END AND MID AND BREAK DOWN 3 INSERT FUNCTION IF NEEDED
void _insert2(struct Node* curr, struct Node *pred, struct Node* adjc){//adjc is the node next to current node
    if(pred->next == NULL){//if added at the end of the list
      curr->next= NULL;
      pred->next = curr->prev;
      curr->prev = pred->next; //make them next of previous node and prev of crueent node point to each other
      tail = curr->prev;
    }
    else{//if insert at middle
      curr->next = pred->next; //make next of current point to the same place as previous node
      //connect the pointers of curr and pred node together
      pred->next = curr->prev;
      pred->next = curr->prev;
      //connect the pointers of curr and adjc together
      curr->next= adjc->prev;
      adjc->prev= curr->next;
    }
}
void insert(struct Node* curr, struct Node* pred, struct Node* adjc){
  if(pred == NULL){
  _insert1(curr);
  }
  else{
  _insert2(curr, pred, adjc);
  }
}

void _delete1(){//delete first node
  struct Node* curr; //create a node pointer pointing to the 1st node of the list
  curr->prev = head;
  if(curr->next = NULL){//if there is only 1 node
    head = tail = NULL; //reset to inital condition
  }
  else{//more than 1 deleted node
  head = curr->next; //make the head pointer point to the same place as the next pointer of the delete node
  }
  free(curr);//delete the node
}

void _delete2(struct Node* curr, struct Node* pred, struct Node* adjc){//delete at middle
    pred->next = curr-> next; //make the next of previous node points to the same place as the deletemed node
    adjc->prev = pred->next; //make the prev of the node next to the delete node points to the node preiouvs to delete node
    free(curr);
}

void _delete3(struct Node* curr, struct Node* pred){//delete at end
    pred->next = NULL;
    tail = pred->prev; //make tail point to previous node
    free(curr);
}

void delete(struct Node* curr, struct Node* pred, struct Node* adjc){
    if( pred == NULL){
        _delete1();
     }
     else if( curr->next == NULL){
        _delete3(curr, pred);
     }
     else{
        _delete2(curr, pred, adjc);
     }
}

void disp(){
    struct Node*curr;
    curr->prev= head;//make prev point of curr node points to head
    while(curr != NULL){//as long as the list doesn't ends
        printf("%d\t", curr->data);
        curr = curr->next; //move on to the next node
    }
    printf("\n");
}
// I'LL WORK ON THIS FUNCTION LATER AND THEN COMPILE IT TO SEE IF MY LOGIC IS RIGHT
void test(){
}
