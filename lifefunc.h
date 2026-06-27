// lifefunc.h
// Will Armsworthy
// This function header file contains all function headers for the playlife.c func, with
// the functions houses in the lifefunc.c program.

#define SIZE 40 // this macro defines the size of the board in both dimensions

void board_init(char [SIZE][SIZE]);
void board_disp(char [SIZE][SIZE]);
void cell_add(char [SIZE][SIZE], int, int);
void cell_clear(char [SIZE][SIZE], int, int);
void board_upd(char [SIZE][SIZE]);
int neighbor_count(char [SIZE][SIZE], int, int);
