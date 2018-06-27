//list.c file that implements all functions declared in list.h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct _node {
    int value;
    Node next;
} node;
 

Node new_node(int value){
  Node newNode = malloc(sizeof(node));
  assert(newNode != NULL);
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}


//frees everything malloced for the list  //Question1
void destroy(Node head) {
   Node curNode = head;
   Node prevNode = NULL;

   while (curNode != NULL) {
     prevNode = curNode;
     curNode = prevNode->next;
     free(prevNode);
   }

}

//appends a node of value to the end of the list
Node append(Node head, int value) {

   Node newNode = new_node(value);
   Node curNode = head;
   
   if ( curNode == NULL ) {
      head = newNode;
   } else {
      while ( curNode->next!=NULL ) {
         curNode = curNode->next;
      }
      curNode->next = newNode;
   }
   return head;
}

void printList(Node head){
  Node cur = head;
    while(cur != NULL){
        printf("[%d]->",cur->value);
        cur = cur->next;
    }
    printf("X\n");
}

// returns the length of a linked list
int length(Node head){
    Node curr=head;
    int counter=0;
    while(curr!=NULL){
        curr=curr->next;
        counter++;
    }
    return counter;
}

// Given a sorted list, insert a node into the list
// preserving sorted order
//given a list 0->1->2->5->7->X
//then sorted_insert(l, 4)
//now the list will be 0->1->2->4->5->7->X

Node sorted_insert(Node head, int val){
    Node newNode = new_node(val);
    Node curr=head;
    if(newNode==NULL){
        exit(1);
    }
    if(head==NULL){
        head=newNode;
    } else if(newNode->value <= curr->value){
        newNode->next=curr;
        head=newNode;
       
    }  else { 
         Node prev = NULL;

         while(curr != NULL && newNode->value > curr->value) {
            prev = curr;
            curr = curr->next;
         }

         prev->next = newNode;
         newNode->next = curr;
    }
/*else{                                                                 //question2
        while(curr!=NULL){
            if(newNode->value >= curr->value && newNode->value <= curr->next->value ){
                newNode->next=curr->next;
                curr->next=newNode;
            }
            curr=curr->next;
        }
            if (newNode->value > curr->value){
                curr->next=newNode;
            } 
    }*/
    
    return head;
    
}

//inserts a node of value AT specified index
//	       0  1  2  3
//given a list 0->1->2->X
//then insertAt(l, 2, 9);
//                     0  1  2  3  4
//now the list will be 0->1->9->2->X
//if specified index is greater than the length of the list 
//append it to the end
Node insertAt(Node head, int index, int value){
    Node newNode=new_node(value);
    Node curr=head;
    if(newNode==NULL){
        exit(1);
    }
    int i=0;
    Node prev=NULL;
    if(head==NULL){
        head=newNode;
    } else if(index>=length(head)){
        while(i<length(head)-1){
            curr=curr->next;
            i++;
        }
        curr->next=newNode;
    } else if (index==0){
        newNode->next=curr;
        head=newNode;
    } else {
        while(i<index){       
            prev=curr;
            curr=curr->next;
            i++;
        }
        prev->next=newNode; 
        newNode->next=curr; 
    }
      
  return head;
}

