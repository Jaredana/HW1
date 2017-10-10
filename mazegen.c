#include "input.h"

int Destroyer(char** Maze, int Columns, int rows)
{
    free(Maze);
	/* Just needs to return something */
	return 0;
}

struct ReadMaze Copy_data(struct ReadMaze Maze, struct ReadMaze TMaze)
{
    Maze.Columns = TMaze.Columns;
    Maze.rows = TMaze.rows;
    Maze.start = TMaze.start;
    Maze.end = TMaze.end;
    Maze.MazeData = TMaze.MazeData;
    return Maze;
}

struct ReadMaze Read_Size(FILE *ptr_file)
{
    struct ReadMaze my_data;
    my_data.start = (int*)malloc(sizeof(int) * 5);
    my_data.end = (int*)malloc(sizeof(int)*5);

    if (!ptr_file)
    {
        printf("Oh no! %s\n", strerror(errno));
        /*return my_data; Fail*/
    }
	else if(fscanf(ptr_file, "%i," , &my_data.Columns))
	{
        /* i is rows j is columns */
		int i = 0;
		int j = 0;
		char** Maze;
        fscanf(ptr_file, "%i", &my_data.rows);
		/*
		 * This is to make it so the numbers are the actual array length we want
         * Maze2 for example is 0-17 rows in an array but the rows read in as 18
		 */
        --my_data.rows;
        --my_data.Columns;

        fscanf(ptr_file, " ");
        fscanf(ptr_file, "%i", &my_data.start[0]);
        fscanf(ptr_file, ",");
        fscanf(ptr_file, "%i", &my_data.start[1]);
        fscanf(ptr_file, " ");
        fscanf(ptr_file, "%i,", &my_data.end[0]);
        fscanf(ptr_file, ",");
        fscanf(ptr_file, "%i", &my_data.end[1]);
        fscanf(ptr_file, " ");

        /* Begin reading in maze by allocating memory */
	   	Maze = Create_Maze(my_data);
        while(i <= my_data.rows)
        {
            for (j = 0; j <= my_data.Columns; ++j)
			{
                fscanf(ptr_file, "%c", &Maze[i][j]);
            }
            j = 0;
            ++i;
        }
        printf("Columns %d\n", my_data.Columns);
        printf("Rows %d\n", my_data.rows);
        printf("Start %d , %d\n", my_data.start[0], my_data.start[1]);
        printf("End %d , %d\n", my_data.end[0], my_data.end[1]);
        printf("\n");

        my_data.MazeData = Maze;
        /*Destroyer(Maze, my_data.Columns, my_data.rows);*/
        /*return my_data;*/
    }
	return my_data;
}

char** Create_Maze(struct ReadMaze MazeData)
{
    int i = 0;
    char** Maze;
    Maze = (char**)malloc(sizeof(char *) * MazeData.rows);

    for(i = 0; i <= MazeData.rows; ++i)
    {
        Maze[i] = (char*)malloc(sizeof(char) * MazeData.Columns);
    }
    return Maze;
}

void Display(char** Maze, int Columns, int rows)
{
    int i = 0;
    int j = 0;
    while(i < rows)
	{
        for (j = 0; j < Columns; ++j) {
            printf("%c", Maze[i][j]);
        }
        ++i;
    }
}
