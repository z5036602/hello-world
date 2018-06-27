#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define TRUE 1
#define FALSE 0 
int non_decreasing (int a[],int num);
int main(int argc,char *argv[]){
    int num=0;
    int *array=malloc(sizeof(int)*10);//question?
    int result=0;
    int c=0;
    while(c!= '\n'){
        c=getchar();
        if(isdigit(c)){
            array[num]=c;
            num++;
        }
    }
    result=non_decreasing(array,num);
    printf("%d\n",result);
    return EXIT_SUCCESS;
}

int non_decreasing (int a[],int num){
    int i=0;
    int result=FALSE;
    while(i<num-1){ //notice here
        if(a[i]<=a[i+1]){
            result=TRUE;
        }
        i++;
     }
 
    return result;
}   
