#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

typedef struct node Node;

typedef struct list List;

List * makelist();
void addHead(int data, List * list);
void addTail(int data, List * list);
void delete(int data, List * list);
void display(List * list);
void destroy(List * list);

#endif
