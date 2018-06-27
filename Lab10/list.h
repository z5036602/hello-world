//header file for a Linked List structure
//contains functions that can be implemented on a Linked List

typedef struct _node* Node;

//Create new node
Node new_node(int value);
//frees everything malloced for the list
void destroy(Node head);
//appends a node of value to the end of the list
Node append(Node head, int value);
// Given a sorted list, insert a node into the list
// preserving sorted order
Node sorted_insert(Node head, int val);
// returns the length of a linked list
int length(Node head);
//prints the contents of a list
void printList(Node head);
//Insert node at position
Node insertAt(Node head, int index, int value);
