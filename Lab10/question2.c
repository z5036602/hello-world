#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char* insert_string (char s[],char t[],int k);
int main(int argc, char *argv[]){
    char s[100]={0};
    char t[100]={0};
    int k;
    char *result={0};
    scanf("%d",&k);
    strcpy(s,"abcd");//question about '\0\'
    strcpy(t,"12");
    result=insert_string(s,t,k);//does result have to be a ponter??
    printf("%s\n",result);
    return EXIT_SUCCESS;
}
char* insert_string (char s[],char t[],int k){
    int i=0;
    int o=0;
    char *u=malloc(sizeof(char)*10);

    if(k<0){
        while(i<strlen(t)){
            u[i]=t[i];
            i++;
        }
        while(o<strlen(s)){
            u[i]=s[o];
            o++;
            i++;
        }
        u[i]='\0';

    } else if( k>=0 && k<strlen(s)){
        while(i<k){
            u[i]=s[i];
            i++;
        }
        while(o<strlen(t)){
            u[i]=t[o];
            i++;
            o++;
        }
        while(k<strlen(s)){
            u[i]=s[k];
            k++;
            i++;
        }
        u[i]='\0';
    } else {
        while(i<strlen(s)){
            u[i]=s[i];
            i++;
        }
        while(o<strlen(t)){
            u[i]=t[o];
            i++;
            o++;
        }
        u[i]='\0';
    } //if i dont need return it do i have to use malloc and if i need to return it,how do i free it?
      //does it have to empty to use strcpy.is that we making certain rule that end of string have to be NULL?
    return u;
}

    //have to malloc???
    /*int i=0;
    int counter=0;
    char *result=malloc(sizeof(char)*10);
    char save1[100]={0};
    char save2[100]={0};//when i have to use pointer type string? empty set.
    if(k>0&&k<4){
        while(i<k){
           save1[i]=s[i];
            i++;
        }
        while(k<strlen(s)){
           save2[counter]=s[k];
            k++;
            counter++;
        }
        strcat(save1,t);
        strcat(save1,save2);
        strcpy(result,save1);
    } else if(k<=0){
        strcat(t,s);
        strcpy(result,t);
    } else if (k>=strlen(s)){
        strcat(s,t);
        strcpy(result,s);
    }
    return result;
}*/
