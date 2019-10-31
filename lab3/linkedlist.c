#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
struct Node {
  int data;
  int sc;
  struct node * next;
};

struct List {
  Node * head;
};

Node * createnode(int data);

Node * createnode(int data){
  Node * newNode = malloc(sizeof(Node));
  if (!newNode) {
    return NULL;
  }
  newNode->data = data;
  newNode->sc = 0;
  newNode->next = NULL;
  return newNode;
}

List * makelist(){
  List * list = malloc(sizeof(List));
  if (!list) {
    return NULL;
  }
  list->head = NULL;
  return list;
}

void display(List * list) {
  Node * current = list->head;
  if(list->head == NULL)
    return;

  for(; current != NULL; current = current->next) {
    printf("%d %d\n", current->data, current->sc);
  }
}

void appendTail(int data, List * list){
  Node * current = NULL;
  if(list->head == NULL){
    list->head = createnode(data);
  }
  else {
    current = list->head;
    while (current->next!=NULL){
      current = current->next;
    }
    current->next = createnode(data);
  }
}
void appendHead(int data, List* list){
  Node * current = list->head;
  Node * newhead = createnode(data);
  newhead->next = current;
  list->head = newhead;
}
void delete(int data, List * list){
  Node * current = list->head;
  Node * previous = current;
  while(current != NULL){
    if(current->data == data){
      previous->next = current->next;
      if(current == list->head)
        list->head = current->next;
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void destroy(List * list){
  Node * current = list->head;
  Node * next = current;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}
