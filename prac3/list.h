typedef struct lnode Lnode;

struct lnode {
  int    data;
  Lnode *next;
};

Lnode * makeNode( int );
Lnode *  append( Lnode *new_node, Lnode *head );
void   printList( Lnode *head );
void    freeList( Lnode *head );

Lnode *removeDuplicates (Lnode *head);
Lnode *backToFront (Lnode * head);
