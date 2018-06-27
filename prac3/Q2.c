#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
void sanitize(char *s);
int main (int argc, char *argv[]){
    char s[100]={0};
    fgets(s,100,stdin);
    s[strlen(s)-1]='\0';
    sanitize(s);
    printf("%s",s);
    return EXIT_SUCCESS;


}
void sanitize(char *s){
    char a[100]={0};
    int i=0;
    int k=0;
    //int num=0;
    while(i<strlen(s)){
        //int j=0;
        int j=0;
        int unique=1;
        while(j<strlen(s)){
            if(s[i]==a[j]){
                unique=0;
                //num++;
            }
            j++;
        }
        if(unique==1){
            a[k]=s[i];
            k++;
        }
        i++;
    }
    strcpy(s,a);
}
