
#include "input.h"
//Function Declarations
struct ReadMaze Read_Size(FILE *ptr_file);
char** Create_Maze(struct ReadMaze my_data);
struct ReadMaze Copy_data(struct ReadMaze my_data, struct ReadMaze TMaze);
int Destroyer(char** Maze, int Columns, int rows);
void Display(char** Maze, int Columns, int rows);


int main() {
    printf("Hello, TEST!\n");
    //int * top =(int*)malloc(sizeof(int));
    FILE *ptr_file = fopen("maze2.txt", "r");
    FILE *ptr_file2 = fopen("maze3.txt", "r");

    //Read in Maze Data temp1 is Maze 1 and temp2 is Maze 2
    struct ReadMaze Maze1, Maze2;

    Maze1 = Copy_data(Maze1, Read_Size(ptr_file));
    Maze2 = Copy_data(Maze2, Read_Size(ptr_file2));

    fclose(ptr_file);
    fclose(ptr_file2);

    //Display(Maze1.MazeData, Maze1.Columns, Maze1.rows);


    return 0;
}

int Destroyer(char** Maze, int Columns, int rows)
{

    free(Maze);
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

struct ReadMaze Read_Size(FILE *ptr_file) {
    struct ReadMaze my_data;
    my_data.start = (int*)malloc(sizeof(int) * 5);
    my_data.end = (int*)malloc(sizeof(int)*5);

    if (!ptr_file)
    {
        printf("Oh no! % s\n", strerror(errno));
        return my_data; //Fail
    }
    if(fscanf(ptr_file, "%i," , &my_data.Columns)) {
        fscanf(ptr_file, "%i", &my_data.rows);
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
        //Begin reading in maze by allocating memory
        char** Maze = Create_Maze(my_data);
        // i is rows j is columns
        int i = 0;
        int j = 0;
        while(i <= my_data.rows)
        {
            for (j = 0; j <= my_data.Columns; ++j) {
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
        //Destroyer(Maze, my_data.Columns, my_data.rows);
        return my_data;
    }
}

char** Create_Maze(struct ReadMaze MazeData)
{
    int i = 0;
    char** Maze;
    Maze = (char**)malloc(sizeof(char *) *MazeData.rows);

    for(i = 0; i <= MazeData.rows; ++i)
    {
        Maze[i] = (char*)malloc(sizeof(char) *MazeData.Columns);
    }
    return Maze;
}

void Display(char** Maze, int Columns, int rows)
{
    int i = 0;
    int j = 0;
    while(i < rows) {
        for (j = 0; j < Columns; ++j) {
            printf("%c", Maze[i][j]);
        }
        ++i;
    }
}