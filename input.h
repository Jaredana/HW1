/*
 * Created by Jared_Dana on 9/28/2017.
 * Modified by Ben Gustafson
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>
/*#include <mem.h> Was throwing errors in Linux */

/*
 * FUNCTION DECLARATIONS
 */

/* Reads in data from the text file and fills the Maze struct and 2D array */
struct ReadMaze Read_Size(FILE *ptr_file);
/* Used for allocating memory for the maze's data */
char** Create_Maze(struct ReadMaze my_data);
/* Maze copy function */
struct ReadMaze Copy_data(struct ReadMaze my_data, struct ReadMaze TMaze);
/* For Deallocating, his method didn't work... */
int Destroyer(char** Maze, int Columns, int rows);
/* Works a little weird */
void Display(char** Maze, int Columns, int rows);

/* Main looper for solving the maze */
void SolveMaze(struct ReadMaze maze);
/* Swap character in maze to show path */
int DrawPath(char* spot);

/* This enum will represent which direction the 'solver' is facing */
enum dir {NORTH, EAST, SOUTH, WEST};

/*
 * This struct will represent a maze
 * MazeData is a 2D array of chars that is filled in from the text file
 * We also read in the data given (number of columns, rows, the start and the end)
 */
struct ReadMaze
{
    int Columns;
    int rows;
    int * start;
    int * end;
    char** MazeData;
};

/*
 * This struct will represent the maze solver
 * The 4 char members hold the state values of the maze in the solver's proximity
 * (They will be rotated respectively if the solver's direction changes)
 * The 2 int values represent the solver's current coordinates in the maze
 * The enum defined earlier keeps track of rotational orientation
 */
struct Solver
{
	char fwd;
	char left;
	char right;
	char rear;
	int row;
	int col;
	enum dir currentDir;
};

#ifndef TEST_INPUT_H
#define TEST_INPUT_H

#endif
