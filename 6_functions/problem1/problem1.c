
#include "problem1.h"
#include <stdio.h>
#include <stdlib.h>

char check_win(char board[3][3])
{
  int count_x = 0;
  int count_y = 0;
  for(int i=0;i<3;i++){             
    for(int j=0;j<3;j++){
      if ((board[i][j]!='x')&&board[i][j]!='o'&&board[i][j]!=' ' ){  // check if any invalid input
        return('0');
      }
      if(board[i][j] == 'x'){
        count_x++;
      }
      if(board[i][j] == 'o'){
        count_y++;
      }
    }
  }
  if(abs(count_y - count_x) >= 2){        // check if players are taking turns (difference with 'x' and 'o' not exceeding 1)
    return('0');}



  for(int y=0;y<3;y++){
  	if((board[0][y] == board[1][y]) && 
  	(board[1][y] == board[2][y]) &&
  	(board[0][y] == board[2][y]) ){        // check whether vertical line cause a win
  		// printf("the %c wins \n",board[1][y]);
  		return(board[1][y]);
  	}
  }

  for(int x=0;x<3;x++){
  	if((board[x][0] == board[x][1]) && 
  	(board[x][1] == board[x][2]) &&
  	(board[x][0] == board[x][2]) ){       // check whether horizontal line cause a win
  		// printf("the %c wins \n",board[x][0]);
  		return(board[x][0]);
  	}
  }

    if((board[0][0] == board[1][1]) && 
  	(board[1][1] == board[2][2]) &&
  	(board[0][0] == board[2][2]) ){         // check whether diagonal line cause a win
  		// printf("the %c wins \n ",board[1][1]);
  		return(board[1][1]);
  	}

    if((board[0][2] == board[1][1]) && 
  	(board[1][1] == board[2][0]) &&
  	(board[0][2] == board[2][0]) ){        // check whether diagonal line cause a win
  		// printf("the %c wins \n",board[2][0]);
  		return(board[2][0]);
  	}


  for(int i=0;i<3;i++){                  // check if there is any space, means the game is still on going
    for(int j=0;j<3;j++){
      if (board[i][j] == ' '){
        return(' ');
      }
    }
  }


return('.');  // no winner
}

