/*
 * Created by Jared Dana on 9/28/2017
 * Modified by Ben Gustafson
 */

#include "input.h"

int main(int argc, char* argv[])
{
    FILE *ptr_file1;
    struct ReadMaze Maze1;
	
	/*
	 * Use command line args to select files
	 * (Instead of hard-coding the names; more flexible)
	 */
	if (argc > 1)
		ptr_file1 = fopen(argv[1], "r");
	else
	{
		printf("\n** NO ARGS, Using maze2.txt **\n-> Use './program [file]'\n\n");
		ptr_file1 = fopen("maze2.txt", "r");
	}

    /* Read in Maze Data - Maze 1 is maze2.txt and Maze 2 is maze3.txt */
    Maze1 = Copy_data(Maze1, Read_Size(ptr_file1));
    Display(Maze1.MazeData, Maze1.Columns, Maze1.rows);

    printf("\n\n\n");
	
    fclose(ptr_file1);

	SolveMaze(Maze1);

    free(Maze1.start);
    free(Maze1.end);
    Destroyer(Maze1.MazeData, Maze1.Columns, Maze1.rows);
    return 0;
}
