#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "list.h"

Lnode * makeNode( int data ){
  Lnode *new_node = (Lnode*)malloc(sizeof(Lnode));
  if( new_node == NULL ) {
    printf("Error: memory allocation failed\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;
  return( new_node);
}


Lnode * append( Lnode *new_node, Lnode *head ){

  if( head == NULL ) {
    head = new_node;
  }
  else {
    Lnode *current = head;
    // find the tail of the list
    while( current->next != NULL ) {
      current = current->next;
    }
    current->next = new_node;
  }
  return( head );
}

void printList( Lnode *head ){

  Lnode *node = head;

  // traverse the list printing each node in turn
  while( node != NULL ) {
    printf("->%d", node->data );
    node = node->next;
  }
  printf("\n");
}

void freeList( Lnode *head ){

  Lnode *node = head;
  Lnode *tmp;

  while( node != NULL ) {
    tmp = node;
    node = node->next;
    free(tmp);
  }
}
Lnode *backToFront (Lnode * head) {
    Lnode *curr=head;
    Lnode *prev=NULL;
    while(curr->next!=NULL){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    curr->next=head;
    return curr;
}
Lnode *removeDuplicates (Lnode *head){
	Lnode *curr=head;
    int i = 0;
    int j = 0;
	while(curr != NULL && curr->next!=NULL)    {
		Lnode *prev=curr;
        j = i;
		while (prev != NULL && prev->next!=NULL){
			Lnode *curr1=prev->next;
            printf("%d %d\n", i, j+1);
			if (curr->data==curr1->data){
                printf("removing\n");
				prev->next=curr1->next;
				free(curr1);
                printf("removed\n");
			} else {
                prev=prev->next;
                j++;
            }

		}
		curr=curr->next;
        i++;
	}
    return head;
}
