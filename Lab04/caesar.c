#include <stdio.h>
#include <stdlib.h>

int rotate_right(int ch);
int rotate_left(int ch);
int encode(int ch, int shift);

int main (int argc, char *argv[]){
	int ch = 0;
        int c;
        int shift = 0;
        printf("Enter shift: ");
        scanf("%d",&shift);
        getchar();     

	printf("Enter Text:\n");
        ch = getchar();
        while(ch != '\n') {
 	       c = encode(ch, shift);
 	       putchar(c);
 	       ch=getchar();
        }
	printf("\n");
	return EXIT_SUCCESS;
}

int rotate_right(int ch){
    int b;
            if(ch>='a'&&ch<='z'){
                 b = ((ch-'a')+1)%26+'a';
                
             }
            else if(ch>='A'&&ch<='Z'){
                 b=((ch-'A')+1)%26+'A';
           
            }
            else b=ch;
            return b;
 
        }
int rotate_left(int ch){
    int b;
           if(ch>='a'&&ch<='z'){
               b=((ch-'a')-1+26)%26+'a'; 
           
           }
           else if (ch>='A'&&ch<='Z'){
               b=((ch-'A')-1+26)%26+'A';
          
          }
           else {
                 b=ch;
            }
           
           return b;
       }
int encode(int ch, int shift){
    int i=0;
        
        if (shift>0) {while(i<shift){
              ch=rotate_right(ch);
              i++;
             }
        }
    
   
        if (shift<0) {while(i>shift){
               ch=rotate_left(ch);
                 i--;
                 }
        }
        return ch;
   }

