typedef struct node* Lnode;
typedef struct list* List;

// Create a new list
List newList(void);
// Create a new node
Lnode new_node(int val);
// Append a node to the end of the list
void append(List l, int val);
// Print current list
void printList(List l);
//Destroy list
void destroy(List l);
//Get number of nodes in the list
int num_nodes(List l);
//print list in reverse order
void print_reverse(List l);
// Extracts unique elements of the list
List extract_unique(List l);
