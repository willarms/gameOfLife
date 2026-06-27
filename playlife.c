// playlife.c
// Will Armsworthy
// This program is the main code for running the Game of Life. Uses function headers in lifefunc.h
// and functions in lifefunc.c. Game can either be played in interactive mode or batch mode. 
// Interactive mode is first and batch mode is second in this program. Both modes use a switch conditional 
// inside of a while loop to handle various inputs, either from standard input or from a file. 

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "lifefunc.h"

#define SIZE 40

int main(int argc, char *argv[]) {
   
   char board[SIZE][SIZE];
   bool i_mode; // if true, interactive mode, if not, batch mode
   FILE* file;
   char choice; 
   int row, col;
   
   if (argc > 2) {
      printf("Error! Too many input files.\n");
      return 0;
   }

   i_mode = (argc == 1);
   board_init(board);
   
   if (i_mode) { // if i_mode equals 1, run interactive mode code
      board_disp(board); // print the board
      while (1) {
         printf("Choose (a,r,n,q,p): ");
         scanf(" %c", &choice);
         switch (choice) {
            case 'a': // add cell specified by input coordinates 
               scanf(" %d %d", &row, &col);
               cell_add(board, row, col);
               break;
            case 'r': // remove the cell specified by input coordinates
               scanf(" %d %d", &row, &col);
               cell_clear(board, row, col);
               break;
            case 'n': // update the board
               board_upd(board);
               break;
            case 'q': // quit the program
               printf("You want to quit.\n");
               return 0;
            case 'p':
               while (1) {
                  board_upd(board);
                  system("clear");
                  board_disp(board);
                  usleep(100000); // pause between movements
               }
               break;
            default:
               printf("Input is not one of the listed choices. Try again.\n");
               break;
         }
      board_disp(board);
      }
   }
   else {
      char input_buff[256];
      file = fopen(argv[1], "r");
      if (file == NULL) {
         printf("Error! File %s couldn't be opened.\n", argv[1]); // if there is an unlocatable file
         return 1;
      }
      while (fgets(input_buff, 256, file)) {
         switch (input_buff[0]) {
            case 'a':
               sscanf(input_buff, "a %d %d", &row, &col);
               cell_add(board, row, col);
               break;
              
            case 'p':
               while(1) {
                  board_upd(board);
                  system("clear");
                  board_disp(board);
                  usleep(100000);
               }
               break;

            default:
               printf("Input from file not valid.\n");
               break;
         }
         system("clear");
         board_disp(board);
      }
      fclose(file);
   }
   return 0;
}      
