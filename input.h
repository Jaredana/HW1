//
// Created by Jared_Dana on 9/28/2017.
//

#include <stdio.h>
#include <malloc.h>
#include <mem.h>

struct ReadMaze
{
    int Columns;
    int rows;
    int * start;
    int * end;
    int * currLine; //I'm gonna read in line by line, sending the data received to the function that will fill the 2d array
};

#ifndef TEST_INPUT_H
#define TEST_INPUT_H

#endif //TEST_INPUT_H

