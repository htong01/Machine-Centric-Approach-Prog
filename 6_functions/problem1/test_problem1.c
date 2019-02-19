
#include "problem1.h"
#include <stdio.h>

int main(int argc, char* argv[])
{

  char board[3][3] = {            // invalid input
    {'x', 'b', 'o'},
    {'o', 'x', 'x'},
    {'o', 'x', 'o'},
  };
  char result = check_win(board); 
  printf("%c\n", result);

   char board2[3][3] = {          // x wins(vertical)
    {'x', 'x', 'o'},
    {'o', 'x', 'x'},
    {'o', 'x', 'o'},
  };
  result = check_win(board2);
  printf("%c\n", result);

   char board3[3][3] = {          // still on going
    {'x', ' ', 'o'},
    {'o', 'x', 'x'},
    {'o', 'x', 'o'},
  };
  result = check_win(board3);
  printf("%c\n", result);

   char board4[3][3] = {           // players not taking turns
    {'x', 'o', 'o'},
    {'o', 'o', 'x'},
    {'o', 'x', 'o'},
  };
  result = check_win(board4);
  printf("%c\n", result);

   char board5[3][3] = {           // all spaced filled but no one win
    {'x', 'o', 'o'},
    {'o', 'x', 'x'},
    {'o', 'x', 'o'},
  };
  result = check_win(board5);
  printf("%c\n", result);

  char board6[3][3] = {           // win(diagnol) but without filling all space
    {'x', 'x', 'o'},
    {'o', 'o', 'x'},
    {'o', 'x', ' '},
  };
  result = check_win(board6);
  printf("%c\n", result);


  return(0);
}

