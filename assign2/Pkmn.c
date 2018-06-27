#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pkmn.h"

const char * const TYPES[] = {
   "Bug",
   "Dark",
   "Dragon",
   "Electric",
   "Fairy",
   "Fighting",
   "Fire",
   "Flying",
   "Ghost",
   "Grass",
   "Ground",
   "Ice",
   "Normal",
   "Poison",
   "Psychic",
   "Rock",
   "Steel",
   "Water"};

// ADD YOUR CODE HERE - any extra typedefs and #defines you'd like to use
#define TRUE 1
#define FALSE 0
//typedef struct _Pkmnheadtail *List;


struct _list {                   //struct of list
    struct _pkmn * head;
    struct _pkmn * tail;
    struct _pkmn * currpoint;  // point to current point;
    int size;
   // ADD YOUR CODE HERE
};

struct _pkmn {
    int id;
    char name[PKMN_NAME_LENGTH];
    double height;
    double weight;
    int type1;
    int type2;
    int evolutionId;
    int found;                      //marked found or not
    struct _pkmn *next;
   // ADD YOUR CODE HERE
};                  //from lecturers method exatly same


// ADD YOUR CODE HERE - any extra structs you'd like to use


// ADD YOUR CODE HERE - any extra helper functions you'd like to use from within this file

const char * getTypeString(int i) {
   return TYPES[i];
}

Pkmn createPkmn(int id, char * name, double height, double weight, int type1, int type2) {
    Pkmn newpokemon=malloc(sizeof(struct _pkmn));
    if(newpokemon==NULL){   //why we need to check it ? make sure wo got space for it
        exit(EXIT_FAILURE);
    }
    newpokemon->id=id;
    strcpy(newpokemon->name,name);
    newpokemon->height=height;
    newpokemon->weight=weight;
    newpokemon->type1=type1;
    newpokemon->type2=type2;
    newpokemon->evolutionId=0;
    newpokemon->found=FALSE;
    newpokemon->next=NULL;
    return newpokemon;                     //initialise the every value in the node
   // ADD YOUR CODE HERE
}

void printCurrentPkmn(PkmnList list) {
    char type[100];
    char type2[100];
    if(list->currpoint==NULL){
        printf("No Pokemon in list.\n");
    } else if(list->currpoint->found==TRUE){                      //if it is found
        if(list->currpoint->type2==-1){                           //if pk has only one type
            strcpy(type,getTypeString(list->currpoint->type1));     //change number to type string
            printf("Id: %03d\n",list->currpoint->id);
            printf("Name: %s\n",list->currpoint->name);
            printf("Height: %.2lfm\n",list->currpoint->height);
            printf("Weight: %.2lfkg\n",list->currpoint->weight);
            printf("Type: %s\n",type);
        } else {
            strcpy(type2,getTypeString(list->currpoint->type2));    //change number to type string
            strcpy(type,getTypeString(list->currpoint->type1));     //change number to type string
            printf("Id: %03d\n",list->currpoint->id);
            printf("Name: %s\n",list->currpoint->name);
            printf("Height: %.2lfm\n",list->currpoint->height);
            printf("Weight: %.2lfkg\n",list->currpoint->weight);
            printf("Type: %s/%s\n",type,type2);
        }
    } else if(list->currpoint->found==FALSE){                      //if it is not found
            int counter=0;
            printf("Id: %03d\n",list->currpoint->id);
            printf("Name: ");
            while(counter<strlen(list->currpoint->name)){
                printf("*");
                counter++;
            }
            printf("\n");
            printf("Height: --\n");
            printf("Weight: --\n");
            printf("Type: --\n");
    }
   // ADD YOUR CODE HERE
}


PkmnList createPkmnList() {
    PkmnList list=malloc(sizeof(struct _list));
    if(list==NULL){
        printf("Out of Memory.\n");
        return EXIT_SUCCESS;
    }
    list->head=NULL;
    list->tail=NULL;                    //initialise everything
    list->currpoint=NULL;
    list->size=0;
    return list;
}

void freePkmnList(PkmnList list) {
    Pkmn curr=list->head;
    Pkmn restofList=NULL;
    while(curr!=NULL){
        restofList=curr->next;
        free(curr);
        curr=restofList;
    }
    free(list);
   // ADD YOUR CODE HERE
}

void addPkmnToList(PkmnList list, Pkmn pkmn) {
    if (list->head==NULL){
        list->head=pkmn;
        list->currpoint=pkmn;
    } else {
        list->tail->next=pkmn;
    }
    list->tail=pkmn;
    list->size=list->size+1;// ADD YOUR CODE HERE
}

void printPkmnList(PkmnList list) {
    Pkmn curr=list->head;
    if(curr==NULL){
        printf("No Pokemon in list.\n");
    }
    while(curr!=NULL){
        if(list->currpoint==curr){
            if(curr->found==TRUE){              /*print special curr --> and also divided it into two parts found or not found*/
                printf("-->");
                printf("#%03d: %s\n",curr->id,curr->name);
            } else{
                int counter=0;
                printf("-->");
                printf("#%03d: ",curr->id);
                while(counter<strlen(curr->name)){// print asterisks
                    printf("*");
                    counter++;
                }
                printf("\n");
            }
        } else {
            if(curr->found==TRUE){
                printf("   #%03d: %s\n",curr->id,curr->name);
            } else{
                int counter=0;
                printf("   #%03d: ",curr->id);
                while(counter<strlen(curr->name)){ //print asterisks
                    printf("*");
                    counter++;
                }
                printf("\n");
            }
        }
        curr=curr->next;
    }
    printf("\n"); // ADD YOUR CODE HERE
}

void nextPkmn(PkmnList list) {                //change curr pointer move to next one in the list struct basically .
    Pkmn curr=list->currpoint;
    if(curr==list->tail){
        list->currpoint=curr;
    } else{
        curr=curr->next;    //can i do list->currpont =.......->currpoint->next?
        list->currpoint=curr;
    }
    // ADD YOUR CODE HERE
}

void prevPkmn(PkmnList list) {
    Pkmn prev=list->head;
    Pkmn curr=list->currpoint;
    if(curr==list->head){
        prev=list->head;
    } else{
        while(prev->next!=curr){            //stop at curr pointer and move current curr pointer to previous one
            prev=prev->next;
        }
    }
    list->currpoint=prev;
    // ADD YOUR CODE HERE
}

void jumpToPkmn(PkmnList list, int id) {   //change curr pointer to pkmn node with that id
    Pkmn curr=list->currpoint;
    Pkmn checkid=list->head;
    int gotthepk=FALSE;
    while(checkid!=NULL){
        if(id==checkid->id){
            list->currpoint=checkid;
            gotthepk=TRUE;
        }
        checkid=checkid->next;
    }
    if(gotthepk==FALSE){
        list->currpoint=curr;
    }
   // ADD YOUR CODE HERE
}

void removePkmn(PkmnList list) {
    if(list->size>0){
        if(list->size == 1) {
            free(list->head);
            list->head=NULL;
            list->tail=NULL;
            list->currpoint=NULL;
            list->size=0;//can i ?
        }  else {
            Pkmn nTF=list->head;
            Pkmn prev=NULL;
            while(nTF!=list->currpoint){    //move the counter to the curr point
                prev=nTF;
                nTF=nTF->next;
            }
            if(nTF==list->head){
                list->head=nTF->next;
                list->currpoint=nTF->next;   //change the curr pointer after remove
            } else if(nTF==list->tail){
                prev->next=NULL;
                list->tail=prev;
                list->currpoint=prev; //change the curr pointer after remove
            } else{
                prev->next=nTF->next;
                list->currpoint=prev->next; //change the curr pointer after remove
            }
            free(nTF);
            list->size--;
        }
    }
   // ADD YOUR CODE HERE
}

//Stage 3 Functions
void findPkmn(int seed, int factor, int numberOfNewPkmn, PkmnList list) {
    int counter1=0;
    srandom(seed);
    Pkmn curr = NULL;
    while(counter1 != numberOfNewPkmn){
        int i=random()%factor;
        curr=list->head;
        while(curr!=NULL){              //change the found of pkmn node with random id to true
            if(i==curr->id){
                curr->found=TRUE;
                counter1++;
            }
            curr=curr->next;

        }
    }



    // ADD YOUR CODE HERE
}

int totalFound(PkmnList list) {               //count the number of Pkmn nodes with found is true
    int numoffpk=0;
    Pkmn curr=list->head;
    while(curr!=NULL){
        if(curr->found==TRUE){
            numoffpk++;
        }
        curr=curr->next;
    }
   // ADD YOUR CODE HERE
   return numoffpk;
}


// Stage 4 Functions
void addEvolution(PkmnList list, int pkmnId, int evolutionId) {       //change the evolutionId of nodes to the evolutioned pokemon id
    Pkmn curr=list->head;
    while(curr!=NULL){
        if(pkmnId==curr->id){
        curr->evolutionId=evolutionId;

        }
        curr=curr->next;
    }
   // ADD YOUR CODE HERE
}

void showEvolutions(PkmnList list) {
    int evolutionPk=FALSE;
    int evolutionPk1=FALSE;
    if(list->currpoint==NULL){
        printf("No Pokemon in list.\n");
    } else {
        Pkmn curr=list->head;
        Pkmn curr1=list->head;
        Pkmn temp=NULL;

        if(list->currpoint->evolutionId==0){           //print first pkmn on evolution chain(here check if it has second evolution)
            if(list->currpoint->found==TRUE){           //found
                printf("#%03d ",list->currpoint->id);
                printf("%s\n",list->currpoint->name);
            } else{                                     // not found
                int counter=0;
                printf("#%03d ",list->currpoint->id);
                while(counter<strlen(list->currpoint->name)){
                    printf("*");
                    counter++;
                }
                printf("\n");
            }

        } else {                                        //it has evolution
            if(list->currpoint->found==TRUE){          // it is found
                printf("#%03d ",list->currpoint->id);
                printf("%s",list->currpoint->name);
            } else{                                    //not found
                printf("#%03d ",list->currpoint->id);
                int counter=0;
                while(counter<strlen(list->currpoint->name)){
                    printf("*");
                    counter++;
                }
            }
        }
        while(curr!=NULL){                                  //print the sceond pkmn on evolution chain
            if(list->currpoint->evolutionId==curr->id&&
                list->currpoint->evolutionId!=0){
                evolutionPk=TRUE;
                if(curr->evolutionId==0){                   //check whether second pkmn has evolution
                    if(curr->found==TRUE){           //found
                        printf(" --> #%03d ",curr->id);
                        printf("%s\n",curr->name);
                    } else{                                     // not found
                        int counter1=0;
                        printf(" --> #%03d ",curr->id);
                        while(counter1<strlen(curr->name)){
                            printf("*");
                            counter1++;
                        }
                        printf("\n");
                    }
                } else {                                        // it has evolution
                    if(curr->found==TRUE){           //found
                        printf(" --> #%03d ",curr->id);
                        printf("%s",curr->name);
                    } else{                                     // not found
                        int counter1=0;
                        printf(" --> #%03d ",curr->id);
                        while(counter1<strlen(curr->name)){
                            printf("*");
                            counter1++;
                        }
                    }
                }
                temp=curr;     //save the info of second PKmn
            }
            curr=curr->next;
        }
        if(evolutionPk==FALSE){       //if it  second evolution not in the list
            printf(" --> #%d ?????",list->currpoint->evolutionId);
            exit(EXIT_FAILURE);
        } else if (temp->evolutionId!=0){   // if it does, continue the chain
            while(curr1!=NULL){
                if(temp->evolutionId==curr1->id){
                    evolutionPk1=TRUE;
                    if(curr1->found==TRUE){           //found
                        printf(" --> #%03d ",curr1->id);
                        printf("%s\n",curr1->name);
                    } else{                                     // not found
                        int counter2=0;
                        printf(" --> #%03d ",curr1->id);
                        while(counter2<strlen(curr1->name)){
                            printf("*");
                            counter2++;
                        }
                        printf("\n");
                    }

                }
                curr1=curr1->next;
            }

        }
        if (evolutionPk1==FALSE){                            // if the third not in the list
            printf(" --> #%03d ?????\n",temp->evolutionId);
        }
    }
}


// Stage 5 Functions
PkmnList getPkmnOfType(PkmnList list, int type) {       //serach the type then add in the list
    PkmnList typelist=createPkmnList();
    Pkmn curr=list->head;
    while(curr!=NULL){
        if(type==curr->type1||type==curr->type2){
            addPkmnToList(typelist,curr);
        }
        curr=curr->next;
    }

   // ADD YOUR CODE HERE
    return typelist;
}

/*PkmnList getFoundPkmn(PkmnList list) {
    PkmnList foundlist=createPkmnList();
    Pkmn curr=list->head;
    while(curr!=NULL){
        if(curr->found==TRUE){

            addPkmnToList(foundlist,curr);
        }
        curr=curr->next;
    }
    Pkmn curr1=foundlist->head;
    Pkmn temp=NULL;
    Pkmn largestidnode=list->head;
    while (curr1!=NULL){
        temp=curr1;
        if(temp->id>largestidnode->id){
            largestidnode=temp;
            largestidnode->next=curr1;
        }
        curr1=curr1->next;
    }

// ADD YOUR CODE HERE
        return NULL;
}
PkmnList searchByName(PkmnList list, char text[]) {
   // ADD YOUR CODE HERE
   return NULL;
}
*/
