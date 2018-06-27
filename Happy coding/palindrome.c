#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define TRUE 1
#define FALSE 0
#define  MAXLEN  128
int isPalindrome (char input[]);

int main(int argc,char *argv[]){
    int p=0;
    char s[MAXLEN];
	printf("Enter string:\n");
    fgets( s, MAXLEN, stdin );
    s[strlen(s)-1] = '\0'; 
    p=isPalindrome(s);
    if (p==TRUE){
        printf("Yes, is a palindrome.\n");
    } else {
        printf("No, not a palindrome.\n");
    }
   
 
	return EXIT_SUCCESS;
}




int isPalindrome (char input[]){
    int i=0;
    int j=strlen(input)-1;
    int palindrome=TRUE;
	
    while(i<j){
        if(!isalpha(input[i])){
            i++;
        } else if(!isalpha(input[j])){
            j--;
        } else{
            if(toupper(input[i])!=toupper(input[j])){
                palindrome=FALSE;
            }
			i++;
            j--;
        }
            
    }

	return palindrome;
}



