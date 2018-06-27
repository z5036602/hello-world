#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
#define NOUGHTS 0
#define CROSSES 1
#define EMPTY 2
//0 ture 1 false



void scanBoard( int board[SIZE][SIZE] );
void printBoard( int board[SIZE][SIZE] );
int getWinner(int board[SIZE][SIZE]);

int main (int argc,char *argv[]){
    int board[SIZE][SIZE];
    int winner;
    printf("Please enter the board:\n");
    scanBoard( board );

    printf("Here is the board:\n");
    printBoard( board );

    winner=getWinner(board);
    if( winner == 3 ) {
        printf("No Winner\n");
    }
    else if( winner == NOUGHTS ) {
        printf("Noughts Win\n");
    }
    else {
        printf("Crosses Win\n");
    }    

    return 0;
}

void scanBoard( int board[SIZE][SIZE] ) {
   int r,c;
   for( r=0; r < SIZE; r++ ) {
       for( c=0; c < SIZE; c++ ) {
           scanf("%d",&board[r][c]);
       }
    }
}
void printBoard( int board[SIZE][SIZE] ){
    int r,c;
    for( r=0; r < SIZE; r++ ) {
        for( c=0; c < SIZE; c++ ) {
            if( board[r][c] == NOUGHTS ) {
            printf(" O");
            }
            if( board[r][c] == CROSSES ) {
            printf(" X");
            }
            if( board[r][c] == EMPTY ){
            printf(" .");
            }
        }
        printf("\n");
    }
      printf("\n");
}

int getWinner(int board[SIZE][SIZE]){
    int r=0,c=0;
    int winner =3;
    int over;
    
      // check r
    for( r = 0; r < SIZE && winner==3 ; r++ ) {
        over=0;
        for( c = 0; c < SIZE-1; c++ ) {
            if(board[r][c] == EMPTY
        	|| board[r][c] != board[r][c+1]) {
                over=1;
                     
            }
        }
         if(over==0){
            winner = board[r][0];
         }
      }
				
      //check c
      for( c = 0; c < SIZE&&winner==3 ; c++ ) {
           over=0;
        for( r = 0; r < SIZE-1; r++ ) {
            if(board[r][c] == EMPTY
    	    || board[r][c] != board[r+1][c]){
                over=1;//question
                 
             }
         }
         if(over==0){
            winner = board[0][c];   //only one output break the loop
         }
       }
       //check backward diagnal
       if (winner == 3 && board[0][0] != EMPTY ){
            over=0;//use of reset over=0
           for( r = 0; r < SIZE-1; r++ ) {
               if(board[r][r]!= board[r+1][r+1]){
      
                   over=1;// if there is a one then if cant work, before i did is if there is a same then if can work which cant be use at sit 110 etc.
                 
               }
           }
           if(over==0){
                winner = board[0][0];
           }
        }
       //check forward diagonal
    if ( winner == 3 && board[0][SIZE-1] != EMPTY ){
        over=0;
        for( r = 0; r < SIZE-1; r++ ) {
            if(board[r][SIZE-r-1]!= board[r+1][SIZE-r-2]){
             
                  over=1;
             
          }
       }
            if(over==0){
                winner = board[0][SIZE-1];
        }
    }
        return winner;
}



     
	
