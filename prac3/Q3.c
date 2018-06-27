#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
char * twentify(char s[]);
int main(int argc,char *argv[]){
    char s[100]={0};
    char *string=NULL;
    fgets(s,100,stdin);
    s[strlen(s)-1]='\0';
    string=twentify(s);
    printf("%s",string);
    return EXIT_SUCCESS;
}
char * twentify(char s[]){
    char *u=malloc(sizeof(char)*100);
    int i=0;
    int k=0;
    while(i<strlen(s)){
        if(s[i]!=' '){
            u[k]=s[i];
            k++;
        } else {
            u[k]='%';
            u[k+1]='2';
            u[k+2]='0';
            k=k+3;
        }
        i++;
    }

    return u;
}
