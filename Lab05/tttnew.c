
    #include<stdio.h> 

    #define FALSE    0
    #define TRUE     1

    #define SIZE     3
    #define NONE    -1
    #define NOUGHTS  0
    #define CROSSES  1
    #define EMPTY    2

    void  scanBoard( int board[SIZE][SIZE] );
    void printBoard( int board[SIZE][SIZE] );
    int   getWinner( int board[SIZE][SIZE] );

    int main( void )
    {
        int board[SIZE][SIZE];
        int winner;

        printf("Please enter the board:\n");
        scanBoard( board );
       
        printf("Here is the board:\n");
        printBoard( board );

        //Find and print the winner
        winner = getWinner( board );
        if( winner == NONE ) {
          printf("There is no winner\n");
        }
        else if( winner == NOUGHTS ) {
          printf("Noughts win\n");
        }
        else {
          printf("Crosses win\n");
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

    void printBoard( int board[SIZE][SIZE] )
    {
      int r,c;
      for( r=0; r < SIZE; r++ ) {
        for( c=0; c < SIZE; c++ ) {
          if( board[r][c] == NOUGHTS ) {
            printf(" O");
          }
          else if( board[r][c] == CROSSES ) {
            printf(" X");
          }
          else {
            printf(" .");
          }
        }
        printf("\n");
      }
      printf("\n");
    }

    int getWinner( int board[SIZE][SIZE] )
    {
      int gameOver;
      int winner = NONE;
      int r,c;

      // check rows
      for( r = 0; r < SIZE && winner == NONE; r++ ) {
        gameOver = TRUE;
        for( c = 0; c < SIZE-1; c++ ) {
          if(   board[r][c] == EMPTY
    	 || board[r][c] != board[r][c+1]) {
            gameOver = FALSE;
          }
        }
        if( gameOver ) {
          winner = board[r][0];
        }
      }
      // check columns
      for( c = 0; c < SIZE && winner == NONE; c++ ) {
        gameOver = TRUE;
        for( r = 0; r < SIZE-1; r++ ) {
          if(   board[r][c] == EMPTY
    	 || board[r][c] != board[r+1][c]) {
            gameOver = FALSE;
          }
        }
        if( gameOver ) {
          winner = board[0][c];
        }
      }
      // check forward diagonal
      if( winner == NONE && board[0][0] != EMPTY ) {
        gameOver = TRUE;
        for( r = 0; r < SIZE-1; r++ ) {
          if( board[r][r] != board[r+1][r+1] ) {
            gameOver = FALSE;
          }
        }
        if( gameOver ) {
          winner = board[0][0];
        }
      }
      // check backward diagonal
      if( winner == NONE && board[0][SIZE-1] != EMPTY ) {
        gameOver = TRUE;
        for( r = 0; r < SIZE-1; r++ ) {
          if( board[r][SIZE-1-r] != board[r+1][SIZE-2-r]) {
            gameOver = FALSE;
          }
        }
        if( gameOver ) {
          winner = board[0][SIZE-1];
        }
      }

      return winner;
    }
