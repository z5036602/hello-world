#include <stdio.h>
#include <stdlib.h>
#include "Pkmn.h"

void printMenu();

int main(int argc, char * argv[]) {

    PkmnList list = createPkmnList();

    printMenu();
    char selection;
    scanf(" %c", &selection);
    while(selection != 'q') {
        if(selection == 'a') {
            int id = 0;
            char name[PKMN_NAME_LENGTH]={0};
            double height = 0;
            double weight = 0;
            int type1 = 0;
            int type2 = 0;
            printf("Id: ");
            scanf("%d", &id);
            printf("Name: ");
            scanf("%s", name);
            printf("Height: ");
            scanf("%lf", &height);
            printf("Weight: ");
            scanf("%lf", &weight);
            printf("Type: ");
            scanf("%d", &type1);
            printf("Type: ");
            scanf("%d", &type2);
            Pkmn pokemon = createPkmn(id, name, height, weight, type1, type2);
            addPkmnToList(list, pokemon);
        } else if (selection == 'p') {
            printPkmnList(list);
        } else if (selection == 'd') {
            printCurrentPkmn(list);
        } else if (selection == '>') {
            nextPkmn(list);
            printPkmnList(list);
        } else if (selection == '<'){
            printf("x\n");
            prevPkmn(list);
            printPkmnList(list);
        } else if (selection == 'j'){
            int id=0;
            printf("Id: ");
            scanf("%d",&id);
            jumpToPkmn(list,id);
        } else if (selection == 'r'){
            removePkmn(list);
        } else if (selection == 'f'){
            int seed;
            int numberOfNewPkmn;
            int factor;
            printf("Seed: ");
            scanf("%d",&seed);
            printf("Factor: ");
            scanf("%d",&factor);
            printf("Number to find: ");
            scanf("%d",&numberOfNewPkmn);
            findPkmn(seed,factor,numberOfNewPkmn,list);

        } else if(selection=='e'){
            int idev=0;
            int evolutionId=0;
            printf("Id of original Pokemon: ");
            scanf("%d", &idev);
            printf("Id of evolution: ");
            scanf("%d", &evolutionId);
            addEvolution(list,idev,evolutionId);

            //totalFound(list);
        } else if (selection=='s'){
            showEvolutions(list);
        } 

      // ADD YOUR CODE HERE (to add more commands which can execute)

        printMenu();
        scanf(" %c", &selection);
    }

    freePkmnList(list);

    return EXIT_SUCCESS;
}

void printMenu() {

    printf("a - Add a Pokemon to the list\n");
    printf("p - Print list\n");
    printf("d - Display details of the current Pokemon\n");
    printf("> - Move to the next Pokemon\n");
    printf("< - Move to the previous Pokemon\n");
    printf("j - Jump to a specific Pokemon\n");
    printf("r - Remove the current Pokemon\n");
    printf("f - Find Pokemon\n");
    printf("c - Count the number of Pokemon which have been found\n");
    printf("e - Add an evolution to a Pokemon\n");
    printf("s - Show the evolutions of the current Pokemon\n");
    printf("q - Quit\n");
}
