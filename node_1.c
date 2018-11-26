#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node * next;
};
struct Node * head = NULL;

struct Node * make_new_node (int m){
  struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = m;
  new_node->next = NULL;
  return new_node;
}

void insertNode(int x){
  struct Node * newNode = make_new_node(x);
  if (head== NULL){
    head =  newNode;
    return;
    }
    struct Node * tempNode = head;
    
    while (tempNode->next != NULL){
      tempNode = tempNode->next;
    }
    tempNode->next = newNode;
}

void deleteNodeAtEnd(){
  if (head == NULL) return;
  struct Node * temp =  head;
  
  while(temp->next && temp->next->next != NULL){
    temp =  temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}

int main(void) {

  for (int i=1;i<=20;i++){
    insertNode((100+i*2));
  }
  deleteNodeAtEnd();

  struct Node * temp_node = head;  
  int counter = 0;
  while( temp_node != NULL) {  
    printf("counter %d and node data %d \n",counter+1, temp_node->data );
    counter++;
    temp_node = temp_node->next;
  }

  return 0;
}
