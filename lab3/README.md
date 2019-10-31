My solution for the third lab of my Operating Systems course. Assignment is located in assignment.txt.

I use a modified version of the example code given in the lab section, as well as a modified linked list implementation found here: https://github.com/skorks/c-linked-list

Using a linked list implementation instead of an array simplifies the implementation of both the FIFO and LRU algorithms, and makes the SC algorithm slightly less complicated. In fact, only the SC algorithm needs another significant function call
