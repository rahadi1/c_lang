// ########## LINKED LIST ##########
/*
- SOURCE: log2base2.com


- ## BASIC LINKED LIST
- Linked list is a linear data structure where each node has two parts (1. data and 2. reference to the next node)
- 1. data
     we can store the required information, it can be any data type

- 2. reference to the next node
     it will holds the next node address, it will be pointer data type
					Head Node - starting node of a linked list
					Last Node - node with reference pointer as NULL

- Every node in linked list is a structure data type
- sample:
struct node{

 int data;
 struct node *next;
};

- data will used to store integer value
- *next will use to store the address of next node


- # Create and allocate memory for 3 nodes
- sample:
struct node{

 int data;
 struct node *next;
};

struct node *head, *middle, *last;

head = malloc(sizeof(struct node));
middle = malloc(sizeof(struct node));
last = malloc(sizeof(struct node));


- # Assign value to each node
- sample:
head->data = 10;
middle->data = 20;
last->data = 30;


- # STACK AND HEAD MEMORY
- stack memory stores all the local variables and function calls (static memory)
- heap memory stores all the dynamically allocated variables


- # LINKING EACH NODE
- headnode -> middlenode -> lastnode -> NULL
- This process make the node complete in the heap memory 
- sample:
head->next = middle;
middle->next = last;
last->next = NULL;


- # PRINT EACH NODE DATA IN A LINKED LIST
- algorithm:
  1. Create a temporary node (called "temp") and assign the head node address
  2. Print the data which present in the temp node
  3. After printing the data, move the temp pointer to the next node
  4. Do the above process until we reach the end

- sample:
struct node *temp = head;

while(temp != NULL){

 printf("%d\n",temp->data);
 temp = temp->next;
}


Why do we need to use the temp node instead head?
- If we use the head pointer instead of the temp while printing the linked list, we will miss the track of the starting node. (After printing the data head node will point the NULL).

- To avoid that, we should not change the head node's address while processing the linked list. We should always use a temporary node to manipulate the linked list.

*/
/*

//FULL CODE EXAMPLE

#include <stdio.h>
#include <stdlib.h>

int main(){

struct node{

 int data;
 struct node *next;
};

//declare 3 node
struct node *head, *middle, *last;

//allocating memory for each node
head = malloc(sizeof(struct node));
middle = malloc(sizeof(struct node));
last = malloc(sizeof(struct node));

//assign value to each node
head->data = 10;
middle->data = 20;
last->data = 30;

//connecting each nodes
head->next = middle;
middle->next = last;
last->next = NULL;

//create temporary node
struct node *temp = head;

//printing each node data
while(temp != NULL){

 printf("%d\n",temp->data);
 temp = temp->next;
}
printf("NULL\n");

 return 0;
}

*/


/*
- ## INSERTING A NODE AT THE BEGINNING OF A LINKED LIST

- Algorithm:
  1. Declare a head pointer and make it as NULL
  2. Create a new node with the given data
  3. Make the new node points to the head node
  4. Finally, make the new node as the head node


- 1. Declare a head pointer and make it as NULL
- sample:
struct node{

 int data;
 struct node *next;
};

struct node *head = NULL;

- 2. Create a new node with the given data
- sample:
void addNewNode(struct node **head, int var){

 struct node *newNode = malloc(sizeof(struct node));
 newNode->data = var;
}

- 3. Make the new node next pointer points to the head node
- sample:
void addNewNode(struct node **head, int var){

 struct node newNode = malloc(sizeof(struct node));
 newNode->data = var;

 newNode->next = *head;
}

- 4. Finally, make the new node as the head node
- sample:
void addNewNode(struct node **head, int var){

 struct node newNode = malloc(sizeof(struct node));
 newNode->data = var;

 newNode->next = *head;
 *head = newNode;
}

*/
/*

//FULL CODE EXAMPLE:

#include <stdio.h>
#include <stdlib.h>

struct node{

 int data;
 struct node *next;
};

void addNewNode(struct node **head, int var){

 //2
 struct node *newNode = malloc(sizeof(struct node));
  
 newNode->data = var;

 //3
 newNode->next = *head;

 //4
 *head = newNode;
}

void printNode(struct node *head){

 struct node *temp = head;
 while(temp!=NULL){

  printf("%d\n",temp->data);
  temp = temp->next;
 }
printf("NULL\n");
}

int main(){

 //1
 struct node *head = NULL;
 
 addNewNode(&head,30);
 addNewNode(&head,20);
 addNewNode(&head,10);
 printNode(head);
 return 0;
}


- ## INSERTING A NODE AT THE END OF A LINKED LIST
- Algorithm:
  1. Declare head pointer and make it as NULL
  2. Create a new node with a given data. Make the new node->next as NULL
  3. If the head node is NULL, make the new node as the head
  4. If the head node is not NULL, find the last node, make the last node->next as new node

- 1. Declare head pointer and make it as NULL
- sample
struct node{

 int data;
 struct node *next;
};

- 2. Create a new node with a given data. Make the new code->next as NULL
- sample:
void addLast(struct node *head, int var){

 struct node *newNode = malloc(sizeof(struct node));
 newNode->data = var;
 newCode->next = NULL;
}

- 3. If the head node is NULL, make the new node as the head
- sample:
void addLast(struct node *head, int var){

 struct node *newNode = malloc(sizeof(struct node));
 newNode->data = var;
 newNode->next = NULL;

 if(*head == NULL){

  *head = newNode;
 }
}

- 4. If the head is not NULL, find the last node, make the last node->next as new node
- sample:
void addLast(struct node *head, int var){

 struct node *newNode = malloc(sizeof(struct node));
 newNode->data = var;
 newNode->next = NULL

 if(*head == NULL){

  *head = newNode;
 } else {

  struct node *lastNode = *head;

  while(lastNode->next != NULL){

   lastNode = lastNode->next;
  }
  lastNode->next = newNode;
 }
}


