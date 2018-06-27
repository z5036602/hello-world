#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char* del_string(char s[],int lo,int hi);
int main(int argc, char *argv[]){
    int io=0;
    int hi=0;
    char s[]={'A','B','C','D','E','F'};
    printf("give two inputs\n");
    scanf("%d %d",&io,&hi);
    char *result =del_string(s,io,hi);
    printf("%s\n",result);
    return EXIT_SUCCESS;
}
char* del_string(char s[],int lo,int hi){
    char *u=malloc(sizeof(char)*10);
    int i=0;
    if(lo<hi){
        while(i<lo){
            u[i]=s[i];
            i++;
        }
        while(lo+1<hi){
            u[i]=s[lo+1];
            i++;
            lo++;
        }
        while(hi+1<strlen(s)){
            u[i]=s[hi+1];
            hi++;
            i++;
        }
        u[i]='\0';
    } else if(lo>hi){
      while(i<hi){
          u[i]=s[i];
          i++;
      }
      while(hi+1<lo){
          u[i]=s[hi+1];
          i++;
          hi++;
      }
      while(lo+1<strlen(s)){
          u[i]=s[lo+1];
          lo++;
          i++;
      }
      u[i]='\0';
    } else{
          while(i<hi){
              u[i]=s[i];
              i++;
          }
          while(hi+1<strlen(s)){
            u[i]=s[hi+1];
            hi++;
            i++;
          }
        u[i]='\0';
    }
    return u;
}
