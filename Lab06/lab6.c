#include <stdio.h>

#include <stdlib.h>

int main(int argc, char * argv[]) {

    int i, j, asterisks;

    printf("Enter number:\n");

    scanf("%d", &asterisks);

    for(i = 1; i <= asterisks; i++) {

    for(j = 1; j <= i; j++) {

    printf('*');

    }

    printf("\n");

    }

    return EXIT_SUCCESS;

    }


