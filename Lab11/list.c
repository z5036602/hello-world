#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

struct node{
  int val;
  Lnode next;
};


struct list{
    Lnode head;
    int num_nodes;
};

Lnode new_node(int val){
    Lnode new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Out of memory:(\n");
        exit(1);
    }
    new->val = val;
    new->next = NULL;
    return new;
}
List newList(void){
    List new = malloc(sizeof(struct list));
    if(new == NULL){
        printf("Out of memory:(\n");
        exit(1);
    }
    new->head = NULL;
    new->num_nodes = 0;
    return new;
}

void append(List l, int val){
    assert(l != NULL);
    Lnode cur = l->head;
    Lnode new = new_node(val);
    if(cur == NULL){
        l->head = new;
    }else{
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = new;

    }
    l->num_nodes++;
}

void printList(List l){
    assert(l!= NULL);
    Lnode cur = l-> head;
    while(cur != NULL){
        printf("[%d]->",cur->val);
        cur = cur->next;
    }
    printf("X\n");
}


void destroy(List l){
    assert(l!= NULL);
    Lnode cur = l->head;
    Lnode prev = NULL;
    // free every single element of the list
    while(cur!= NULL){
        prev = cur;
        cur = cur->next;
        free(prev);
    }
    // free the list structure itself
    free(l);
}
int num_nodes(List l){
    return l->num_nodes;
}
//Given a linked list print it out in reverse
//Do not reverse original list
//Example:
//Given linked list [1]->[2]->[3]->X
//print_reverse output: [3]->[2]->[1]->X
void print_reverse(List l){
    assert(l!=NULL);
    Lnode curr=l->head;
    int i=0;
    while(i<num_nodes(l)){
        int j=0;
        while (j<num_nodes(l)-i-1){   //care here curr to curr next need nodes -1 move to the last bit of linkedlist;
            curr=curr->next;
            j++;
        }
        printf("[%d]->", curr->val);
        i++;
    }
    printf("X\n");


}
//Given a linked list create a new list containing only unique
//elements of the current list. The order of the elements should remain
// the same as in original linked list. Do not modify the original list.
//Example
//Input: 1->1->2->3->3->3->0->X   //how to do this if these are not in the consecutive order
//Output:1->2->3->0->X
List extract_unique(List l){
    assert(l!=NULL);
    Lnode curr=l->head;
    List unique = newList();
    if(curr->next!=NULL){
        Lnode fut=curr->next;
        append(unique,curr->val);
        while(curr->next!=NULL){
            fut=curr->next;
            if(curr!=fut){
                append(unique,fut->val);
            }
            curr=curr->next;
        }
    } else {
        append(unique,curr->val);
    }
    return unique;
}
    /*assert(l != NULL);
    List list = newList();
    if(l -> head != NULL) {
        Lnode curr = l->head;
        Lnode swap = curr->next;
        append(list, curr-> val);
        while(swap != NULL) {
            if(curr->val != swap->val) {
                append(list, swap->val);
                curr = swap;
            }
            swap = swap->next;
        }
    }
    return list;*/
