/*
 * Created by Jared_Dana on 9/28/2017.
 * Modified by Ben Gustafson
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>
/*#include <mem.h>*/

/*
 * This struct will essentially represent a maze
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

#ifndef TEST_INPUT_H
#define TEST_INPUT_H

#endif
