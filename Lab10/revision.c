#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc,char *argv[]){
    char *s=malloc(sizeof(char)*1);//its just for initialisation,doesnt mean comp only have that a lot space
    char *t=malloc(sizeof(char)*10);
    strcpy(s,"abcd");//question about '\0\'
    strcpy(t,"12");
    printf("%s\n",s);
    free(s);
    return EXIT_SUCCESS;
}
