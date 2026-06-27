# gameOfLife
Conway's Game of Life Project

A terminal-based implementation of Conway's Game of Life written in C, running on a 40x40 grid.

# Features
Interactive mode — add/remove cells, step through turns manually, or run continuously

Batch mode — pass a file of coordinates on the command line to load a starting configuration

Preset scenes including classic patterns sourced from conwaylife.com:
- Loafer & Heavyweight Spaceship
- R-pentomino (only 5 starting cells, but surprisingly chaotic)
- Gosper Glider Gun (continuously fires gliders)

# Building
Requires gcc. 
Clone the repo and run:
make

# Usage
Interactive:
./playlife

Batch mode:
./playlife <input_file>

Input files should contain commands (a row col to add a cell, p to play) read line by line.
Controls (Interactive Mode)

  Key --> Action
  
  a row col --> Add a cell at (row, col)
  
  r row col --> Remove a cell at (row, col)
  
  n --> Advance one turn
  
  p --> Play continuously
  
  q --> Quit

# Project Structure

playlife.c > Main program logic

lifefunc.c > Game functions (display, update, add, remove)

lifefunc.h > Function headers
