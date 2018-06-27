#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main(int argc,char *argv[]){
    Lnode * l =  makeNode(1);
    l = append(makeNode(1), l);
    l = append(makeNode(2), l);
    l = append(makeNode(2), l);
    l = append(makeNode(2), l);
    l = append(makeNode(3), l);
    printList(l);
    l = removeDuplicates (l);
    //l = backToFront (l);
    printList(l);
    return 0;
}
