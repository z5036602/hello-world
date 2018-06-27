#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
void shift_right (int *array,int n);
int main(int argc,char *argv[]){
    printf("do some shit\n");
    int i=0;
    int c=0;
    int a[100]={0};
    while(c!='\n'){
        c=getchar();
        if(isdigit(c)){
            a[i]=c;
            i++;
        }
    }
    shift_right(a,i);
    int k=0;
    while(k<i){
        printf("%d",a[k]);
        k++;
    }
    printf("\n");
    return EXIT_SUCCESS;

}

void shift_right (int *array,int n){
    int i =0;
    int u[100]={0};
    printf("%d\n",n);
    while(i<n){
        u[(i+1)%n]=array[i]-'0';
        i++;
    }
    int c=0;
    while(c<n){
        array[c]=u[c];
        c++;
    }
}
