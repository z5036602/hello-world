#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

void test_print_reverse(void);
void test_extract_unique(void);

void reverse_one(void);
void unique_empty(void);

int main(void){
    //call individual test functions
    test_print_reverse();
    test_extract_unique();

    return 0;
}


void test_print_reverse(void){
    reverse_one();
    //add any additional functions to test your implementation here
}


void reverse_one(void){
    printf("Testing print_reverse with 1 element\n");
    List new = newList();
    append(new, 0);
    printf("Expected output:\n");
    printf("[0]->X\n");
    printf("Your output:\n");
    print_reverse(new);
    destroy(new);
    printf("=========================\n");
}

//##################################################################
void test_extract_unique(void){
    unique_empty();
    //add any additional functions to test your implementation here
}

void unique_empty(void){
    printf("Testing extract_unique with empty list\n");
    List new = newList();
    List u = extract_unique(new);
    assert(num_nodes(new) == 0);
    assert(num_nodes(u) == 0);
    destroy(new);
    printf("Passed\n");
    printf("=========================\n");
}
