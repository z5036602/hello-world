#include<stdio.h>
#include<stdlib.h>
 
 
int main (int argc,char *argv[]){
    int input=0;
    print"get input"
    scanf("%d",&input);
   
    while(input%2==0){
        input=input/2;
    }

    if (input==1){
       printf("1");
    } else {
       printf("0");
    }

    return EXIT_SUCCESS;
}
