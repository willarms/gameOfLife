// lifefunc.c
// Will Armsworthy
// This file will include all of the functions used for the Game of Life main file ("playlife.c")
// The board initialization file is used to initialize a blank board, the display board function
// is used to display the current board, the add cell function is used to add a cell
// at a user specified location, the clear cell function is used to remove a cell at 
// a user specified location, the update board function is used to update the current board
// from turn to turn, and the neighbor count function counts a specific cell's number 
// of neighbors to determine how that cell should behave in the next turn. 

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "lifefunc.h" // created file that houses all function headers

#define SIZE 40 // macro is used to define both dimensions of the board throughout the program

void board_init(char board[][SIZE]) { // initializes board
   
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         board[i][j] = ' ';
      }
   }
}

void board_disp(char board[SIZE][SIZE]) { // displays board 
   
   printf(" ");
   for (int i = 0; i < SIZE; i++) {
      printf("-");
   }
   printf("\n");

   for (int i = 0; i < SIZE; i++) {
      printf("|");
      for (int j = 0; j < SIZE; j++) {
         printf("%c", board[i][j]);
      }
      printf("|\n");
   }

   printf(" ");

   for (int i = 0; i < SIZE; i++) {
      printf("-");
   }

   printf("\n");
}

void cell_add(char board[SIZE][SIZE], int r, int c) { // r is row num and c is col num
      
   if ((r >= 0) && (r < SIZE) && (c >= 0) && (c < SIZE)) {
      board[r][c] = 'X';
   }
}


void cell_clear(char board[SIZE][SIZE], int r, int c) { // r is row num and c is col num
      
   if ((r >= 0) && (r < SIZE) && (c >= 0) && (c < SIZE)) {
      board[r][c] = ' ';
   }
}

void board_upd(char board[SIZE][SIZE]) {

   int n_count; // this is the count of neighbor cells that are "alive"
   char board2[SIZE][SIZE]; // new board after updating newly alive/dead cells
   board_init(board2);
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         n_count = neighbor_count(board, i, j);
         if (board[i][j] == 'X') {
            if (n_count == 2 || n_count == 3) {
               board2[i][j] = 'X';
            }
            else {
               board2[i][j] = ' ';
            }
         }
         else {
            if (n_count == 3) {
               board2[i][j] = 'X';
            }
            else {
               board2[i][j] = ' ';
            }
         }
      }
   }
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++)
         board[i][j] = board2[i][j];
   }
}

int neighbor_count(char board[SIZE][SIZE], int r, int c) { // this function counts number of neighbor cells that are "alive"

   int count = 0;
   for (int i = r-1; i <= r+1; i++) {
      for (int j = c-1; j <= c+1; j++) {
         if ((i >= 0) && (i < SIZE) && (j >=0) && (j < SIZE) && (!(i == r && j == c))) {
            if (board[i][j] == 'X') count++;
         }
      }
   }
   return count;
}
