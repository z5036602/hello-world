#include <stdio.h>

#include <stdlib.h>

int main(int argc, char *argv[]) {

int i, j, asterisks;


printf("Enter number:\n");

scanf("%d", &asterisks);

int k=asterisks;
int s=1;

for(i = 1; i <= asterisks; i++) {
    
    for(s=1;s<=k-1;s++){
       printf(" ");
    }                                     

    for(j = 1; j <= i; j++) {

       printf("*");

    }

    printf("\n");
    
    k--;
    
    }

    return EXIT_SUCCESS;

}


