#include "Stack.h"
#include "Pancake.h"
#include <stdlib.h>
#include <stdio.h>

struct stack {
    int numPancakes;
    Pancake array[MAX_PANCAKES];
};

Stack createStack(void) {
  Stack newstack=malloc(sizeof(struct stack));
  if(newstack==NULL){
      exit(1);
  }
    newstack->numPancakes=0;
    return newstack;
}
// if stack is already full, do nothing
void addPancake(Stack s, char *topping, int size) {
      if (s->numPancakes<MAX_PANCAKES){
        Pancake p=bake(topping,size);
        s->array[s->numPancakes]=p;
        s->numPancakes++;
    }
}
// if stack is already empty, do nothing
void eatPancake(Stack s){
  if (s->numPancakes>0){
      eat(s->array[s->numPancakes-1]);
      s->numPancakes--;
  }
}

int numPancakes(Stack s) {
    int numPancakes=s->numPancakes;// TO DO
    return numPancakes;
}

int totalSize(Stack s) {
    int totalsize=0;
    int i=0;
    while(i<numPancakes(s)){
        totalsize=totalsize+getSize(s->array[i]);
        i++;
    }
    // TO DO
    return totalsize;
}

void printToppings(Stack s) {
    int i=numPancakes(s);
    if(i!=0){
        i--;
        while(i>-1){
            printf("%s\n",getTopping(s->array[i]));
            i--;
        }
    }// TO DO
}


void consumeStack(Stack s) {
    if(s!=NULL){
        int i=0;
        int num=numPancakes(s);
        while(i<num){
            free(s->array[i]);
            i++;
        }
    }
    free(s);
}
