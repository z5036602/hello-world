#include <stdio.h>
#include <stdlib.h>

int rotate_right(int ch);
int rotate_left(int ch);
int encode(int ch, int shift);

int main (int argc, char *argv[]){
	int ch = 0;
	getchar();
	printf("Enter Text:");
        while(ch != EOF) {
        ch = getchar();
        ch = rotate_right(ch);
        putchar(ch);
        }
                  return EXIT_SUCCESS;
}


       int rotate_right(int ch){
    int b;
            if(ch>='a'&&ch<='z'){
                 b = ((ch-97)+1)%26+97;
                
             }
            if(ch>='A'&&ch<='Z'){
                 b=((ch-65)+1)%26+65;
           
            }
            else {
                 b=ch;
            }
            
            return b;
        }
        int rotate_left(int ch){
                       int b;
           if(ch>='a'&&ch<='z'){
           b=((ch-97)-1)%26+97;
           
           }
       if (ch>='A'&&ch<='Z'){
          b=((ch-65)-1)%26+65;
          
          }
          return b;
       }
