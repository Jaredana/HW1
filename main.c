/*
 * Created by Jared Dana on 9/28/2017
 * Modified by Ben Gustafson
 */

#include "input.h"

int main(int argc, char* argv[])
{
	/* 
	 * Possible To-Do: Use command line args to select files
	 * (Instead of hard-coding the names; more flexible)
	 */
    FILE *ptr_file1 = fopen("maze2.txt", "r");
    FILE *ptr_file2 = fopen("maze3.txt", "r");

    /* Read in Maze Data - Maze 1 is maze2.txt and Maze 2 is maze3.txt */
    struct ReadMaze Maze1, Maze2;
    Maze1 = Copy_data(Maze1, Read_Size(ptr_file1));
    Maze2 = Copy_data(Maze2, Read_Size(ptr_file2));

    fclose(ptr_file1);
    fclose(ptr_file2);

    /*Display(Maze1.MazeData, Maze1.Columns, Maze1.rows);*/

    return 0;
}
