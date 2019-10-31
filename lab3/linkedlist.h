#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
  int data;
  int sc;
  struct Node * next;
} Node;

typedef struct list{
  Node * head;
} List;

List * makelist();
Node * createnode(int data);
void appendHead(int data, List * list);
void appendTail(int data, List * list);
void delete(int data, List * list);
void updateSc(Node *node, int val);
void display(List * list);
void destroy(List * list);

#endif //LINKEDLIST_H
