#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int is_anagram(char s[],char t[]);
int main(int argc,char *argv[]){
    int r=0;
    char s[20+1];//do i need malloc when i use fgets and pointer type string?
    char t[20+1];        //char *string="dafdsafdasfdsafdsaf"; can i edit this string???????and is end of string is '\0',is it automatically formed by comp?
            //same with string which i use fgets?
    printf("give the string1:\n");

    fgets(s,20,stdin);
    s[strlen(s)-1]='\0';
    printf("give the string2:\n");
    fgets(t,20,stdin);
    t[strlen(t)-1]='\0';


    r=is_anagram(s,t);
    printf("%d\n",r);
    return EXIT_SUCCESS;
}




int is_anagram(char s[],char t[]){//can i pass in a pointer type string here
    int k=0;
    int i=0;
    int o=0;
    int z=0;
    int b=0;
    int m=0;
    int c=0;
    int counter=0;
    int counter1=0;
    while(z<strlen(s)){
        if(isalpha(s[z])){
            counter++;
        }
        z++;
    }
    while(b<strlen(t)){
        if(isalpha(t[b])){
            counter1++;
        }
        b++;
    }
    if (counter==counter1){
        while(i<strlen(s)){
            m=0;
            o=0;
            while(o<strlen(t)&& m!=1){
                if(isalpha(s[i])&& s[i]==t[o]){
                    //if(s[i]==t[o]){
                        m=1;

                }
               o++;
            }
            if(m==1){
                c=c+1;
            }

            i++;
        }
        //printf("%d\n",c);
        //printf("%d\n",i);
    } else{
        k=0;
    }
    if(c==counter){
         k=1;
    }

    return k;
}
