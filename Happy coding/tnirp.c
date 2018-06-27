#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define TRUE 1
#define FALSE 0
#define  MAXLEN  128
char *reverse_string(char *s);//does passed in value have to be a pointer type?

int main(int argc,char *argv[]){
    char s[MAXLEN];
	  char* rev;
	  printf("Enter string:\n");
    fgets( s, MAXLEN, stdin );
    s[strlen(s)-1] = '\0';//whats size of array
    rev=reverse_string(s);
    printf("%s\n", rev);
	return EXIT_SUCCESS;
}

char *reverse_string(char *s){
    int i=0;
    int j=strlen（s)－1;//can i use strlen for pointer
    int temp=0;

    while(i<j){
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }

	  return s;
}
