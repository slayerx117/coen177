#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  int sc;
  struct Node * next;
} Node;

typedef struct List{
  Node * head;
} List;

List * makelist();
Node * createnode(int data);
void appendHead(int data, List * list);
void appendTail(int data, List * list);
void delete(int data, List * list);
void display(List * list);
void destroy(List * list);
void replaceTail(List * list, int data);

#endif //LINKEDLIST_H
