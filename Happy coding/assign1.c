#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define FALSE 1
#define TRUE 0 
#define NEUTRAL 3

int* getInput();                                              
int* rerollDice(int* input);                                  
int choiceOperation();
int evaluation(int a[100],int posi,int numofopitions );
int errorChecking( int input[],int pos);
int errorChecking2(int input2[],int pos2);
int errorChecking3(int input[],int pos,int num); 
void print_Array(int* input);
void getScoreOpitons(int input[]);





int main (int argc, char *argv[]){
    
    int* input = {0};
    int operation=0;
    
    input = getInput();
    operation = choiceOperation();
    
    if(operation==3){
        getScoreOpitons(input);
    } else if(operation==2){
        input = getInput();
        operation = choiceOperation();
        if(operation==3){
            getScoreOpitons(input);
        } else if (operation==2){ 
        input = getInput();
            getScoreOpitons(input);
        } else {
            input=rerollDice(input);
            getScoreOpitons(input);
        }
    }
    
    else if(operation==1){
        input=rerollDice(input);
        operation=choiceOperation();
        if(operation==3){
            getScoreOpitons(input);
        } else if (operation==2){ 
            input = getInput();
            getScoreOpitons(input);
        } else {
            input=rerollDice(input);
            getScoreOpitons(input);
        }

    }    
    return EXIT_SUCCESS;
}




int* getInput(){                                                       //get the 5 values of dices at start

    printf("Please enter dice values:\n");
    printf("> ");

    int *input = malloc(sizeof(int)*10);
    int c = 0;
    int flag = 0;
    int NOERROR = TRUE;
    int pos = 0;

    while(c!= '\n'){                                               
        c=getchar();
        if(c== ' '){
            flag = 0;                                                   
        }
        if(c!=' '&& c!='\n'){
            if (flag == 1) {
                printf("\n");
                printf("Incorrect Input Format\n");
                NOERROR=FALSE;                                  /*make sure whenever u type in character type a space at front*/
                exit(0);
            }
            input[pos]=c;
            pos++;
            flag = 1;                                         //reset flag
        }  
    }      

    int error=FALSE; 
    if(NOERROR==TRUE){
        error= errorChecking (input,pos);
    }
    if(error==TRUE){
        exit(0);
    }
    print_Array(input);
    return input;
}




int choiceOperation(){                                        //give user choices and evaluate validity

    printf("Please choose:\n");
    printf(" 1 -> Reroll some dice\n");
    printf(" 2 -> Reroll all dice\n");
    printf(" 3 -> Keep dice\n");
    printf(">");

    int invalidchoice = 0;
    int operation=0;
    int posi = 0;
    int choice[] = {0};
        
    while(invalidchoice!='\n'){                                                 
        invalidchoice=getchar();
        if(invalidchoice>='0'&&invalidchoice<='9'){  
            choice[posi]=invalidchoice - '0';
            posi++;
        }  
    }
    operation=evaluation(choice, posi,3);                         //here i use evaluation function to help evaluate
    return operation;
}



int evaluation(int a[100],int posi,int numofopitions){               //help to evaluate validity of choice of operation (reroll keep etc.)
	int finalchoice;
	if((a[0] <= numofopitions) && (a[0] >=1)) {
		finalchoice=a[0];
	    return finalchoice;
    } else {
        printf("\n");
		printf("Invalid Choice\n");
		exit(0);
	}
}




int errorChecking3(int input[],int pos,int num){                   //check the validity of value of dice they wanna change to entered by user
    int numOfNumber = 0;
    int error=3;
    int i=0;
    int k=1;
    int m=1;
     
    while(i<pos){                                                  
        if(input[i]<'0'||input[i]>'9'){
            while(k==1){
                printf("\n");
                printf("Incorrect Input Format\n");
                k++;
            }
            error=TRUE;
        } else if(input[i]<'0'||input[i]>'6'){
            while(m==1){
                printf("\n");
                printf("Value Out of Range\n");
                m++;
            }
            error=TRUE;
        } else {
            numOfNumber++;                              //count how many numbers  in array
        }
            i++; 
    }
    if (numOfNumber != num && error==3) {
        printf("\n");
        printf("Incorrect Number of Values\n");
        error=TRUE;     
    }
    return error;
} 

int errorChecking2(int input2[],int pos2){                       //check the the validity of the which dice user wanna change
    int error=3;
    int i=0;
    while(i<pos2){
        if(input2[i]<'0'||input2[i]>'9'){
            printf("Incorrect Input Format\n");
            error=TRUE;
            
         } else if(input2[i]<'1'||input2[i]>'5'){
            printf("Dice Number Out of Range\n");
            error=TRUE;
              
         }
            i++;
    }
    return error;
}




int errorChecking( int input[],int pos){                          //check validity of the 5 dices entered by user at start
    int numOfNumber = 0;
    int error=3;
    int i=0;
    int k=1;
    int m=1;
     
    while(i<pos){                                                  
        if(input[i]<'0'||input[i]>'9'){
            while(k==1){
                printf("Incorrect Input Format\n");
                k++;
            }
            error=TRUE;
        } else if(input[i]<='0'||input[i]>'6'){
            while(m==1){
                printf("Value Out of Range\n");
                m++;
            }
            error=TRUE;
        } else {
            numOfNumber++;
        }
            i++; 
     }
         
    if (numOfNumber != 5 && error==3) {
        printf("Incorrect Number of Values\n");
        error=TRUE;     
    }
    return error;
} 




void print_Array(int* input){                                       //print the array 
    int i;
    printf("\n");
    printf("Your dice values are: "); 
    for(i=0;i<5;i++){
        printf("%d ",input[i]-48);
    }
    printf("\n");
}




void getScoreOpitons(int input[]){                                       //get the score opitons and give user the scores they got 
    printf("\n");
    printf("Your score options are:\n");
    
    int countercheck=0;
    int dicearray[100]={0};
    
    while(countercheck<5){                                   //use another array to count the frequency of number shows up
        if(input[countercheck]=='1'){
            dicearray[0]++;
        }
        if(input[countercheck]=='2'){
            dicearray[1]++; 
        }
        if(input[countercheck]=='3'){
            dicearray[2]++;                                 
        } 
        if(input[countercheck]=='4'){
            dicearray[3]++;
        }
        if(input[countercheck]=='5'){
            dicearray[4]++;
        }
        if(input[countercheck]=='6'){
            dicearray[5]++;
        }
        countercheck++;
    }
      
    int small_straight=0;
    int dicearraycounter=0;
    int straightcounter=0;
    int straight=0;
      
    for(dicearraycounter=0;dicearraycounter<6;dicearraycounter++){
        if(dicearray[dicearraycounter]==0){
          	straightcounter++;
        }
    }
    if(straightcounter==1){
        small_straight=1;
        straight=1;
    }
    if(straightcounter==2&&
     ((dicearray[0]!=0&&dicearray[1]!=0)||
      (dicearray[1]!=0&&dicearray[4]!=0)||
      (dicearray[4]!=0&&dicearray[5]!=0))){
      
        small_straight=1;
    }
    if(straightcounter!=1&&straightcounter!=2){   
        small_straight=0;
    }
          
    int P=0;
    int W=0;
    int Q=0;
    int E=0;                    //use of counting help to generate the order of score opitons chance
    int R=0;
    int T=0;
    int check=0;
    int sum=(input[0]-'0')+(input[1]-'0')+(input[2]-'0')
        +(input[3]-'0')+(input[4]-'0');
   
    while(check<6){
        if(dicearray[check]>=3){
            
            printf(" 1 -> Three of a Kind (%d points)\n",sum);
            E=E+1;         

        }
        if(dicearray[check]>=4){
        	
            printf(" 2 -> Four of a Kind (%d points)\n",sum);
            R=R+1;

        }
        if(dicearray[check]==3 && 
         (dicearray[0]==2||dicearray[1]==2||
          dicearray[2]==2||dicearray[3]==2||
          dicearray[4]==2||dicearray[5]==2)){
            
            printf(" 2 -> Full House (25 points)\n");
            T=T+1;
            
        }
    check++;
        
    }
    if(dicearray[2]!=0 && dicearray[3]!=0 && small_straight==1){    
           
       printf(" 1 -> Small Straight (30 points)\n");
       Q=Q+1;
   
    }
    if(dicearray[2]!=0 && dicearray[3]!=0 && 
       straight==1&& (dicearray[1]!=0 && dicearray[4]!=0)){
       
       printf(" 2 -> Straight (40 points)\n"); 
        W=W+1;
    }
   
    if(input[0]==input[1] && input[1]==input[2]&& 
      input[2]==input[3] && input[3]==input[4]){
       
       P=P+1;
       printf(" 3 -> Yahtzee (50 points)\n");
    }
    int numofscoreopitions=E+R+T+Q+W+P+1;
  
    printf(" %d -> Chance (%d points)\n",numofscoreopitions=E+R+T+Q+W+P+1,sum);//here
    printf("> ");	   
   
    int posin = 0;
    int invalidchoice2=0;
    int scorechoice[100]={0};	                             //evaluate validity of socreopitons again!!!!!!
   
    while(invalidchoice2!='\n'){
        invalidchoice2=getchar();
        if(invalidchoice2>='0'&&invalidchoice2<='9'){
			scorechoice[posin]=invalidchoice2-'0';
            posin++;
        } 
    }
    int finalchoice2=evaluation(scorechoice,posin, numofscoreopitions); 
    printf("\n");
    printf("Your score is: ");
    if(finalchoice2==2&&T==1){
        printf("25 points\n");
    } else if((finalchoice2==1||finalchoice2==2) && (E==1||R==1)){
        printf("%d points",sum);
    } else if(finalchoice2==1&& Q==1){
        printf("30 points\n");
    } else if(finalchoice2==2&& W==1){
        printf("40 points\n");
    } else if(finalchoice2==3&& P==1){
        printf("50 points\n");
    } else  {
        printf("%d points\n",sum);
    }
    printf("\n");

}




int* rerollDice(int* input){
    int *input2= malloc(sizeof(int)*10);
    int *input1= malloc(sizeof(int)*10);;
    int pos2=0;
    int pos1=0;
    int c2=0;
    int c1=0;
    int flag2=0;
    int flag1=0;
    int NOERROR2=TRUE; 
    int NOERROR1=TRUE;
    int error2=FALSE;
    int exist = FALSE;
    int error1=FALSE;
    int i=0;
    int j=0;
    int k=0;
    printf("Please enter dice to reroll (1 - 5):\n");
    printf("> ");
    while(c2!= '\n'){                                               
        c2=getchar();
        if(c2== ' '){
            flag2 = 0;
        }
        if(c2!=' '&& c2!='\n'){
            if (flag2 == 1) {
                printf("Incorrect Input Format\n");
                NOERROR2=FALSE;
                exit(0);
            }
        while(i < pos2){
            if (input2[i] == c2){
                exist = FALSE;
            }
            i++;
        }
        if (exist != TRUE){
            input2[pos2]=c2;
            pos2++;
        }
        flag2 = 1;
        }  
    }      
    if(NOERROR2==TRUE){
        error2= errorChecking2 (input2,pos2);
    }
    if(error2==0){
        exit(0);
    }
    printf("Please enter %d values\n",pos2);
    printf("> ");
    while(c1!= '\n'){                                               
        c1=getchar();
        if(c1== ' '){
            flag1 = 0;
        }
        if(c1!=' '&& c1!='\n'){
            if (flag1 == 1) {
                printf("\n");
                printf("Incorrect Input Format\n");
                NOERROR1=FALSE;
                exit(0);
            }
            input1[pos1]=c1;
            pos1++;
            flag1 = 1;
                                   
        }  
          
    }
    if(NOERROR1==TRUE){
        error1= errorChecking3(input1,pos1,pos2);
    }
    if(error1==0){
        exit(0);
    }
    while(k<pos2){
        j=input2[k]-'0'-1;
        input[j]=input1[k];
        k++;
    }
    print_Array(input); 
    return input;
}












