
#include "input.h"

void Read_Size(struct ReadMaze my_data) {
    FILE *ptr_file = fopen("maze2.txt", "r");
    my_data.start = (int*)malloc(sizeof(int) * 5);
    my_data.end = (int*)malloc(sizeof(int)*5);

    if (!ptr_file)
    {
        printf("Oh no! % s\n", strerror(errno));
        return; //Fail
    }
    if(fscanf(ptr_file, "%i," , &my_data.Columns)) {
        fscanf(ptr_file, "%i", &my_data.rows);
        fscanf(ptr_file, " ");
        fscanf(ptr_file, "%i", &my_data.start[0]);
        fscanf(ptr_file, ",");
        fscanf(ptr_file, "%i", &my_data.start[1]);
        fscanf(ptr_file, " ");
        fscanf(ptr_file, "%i,", &my_data.end[0]);
        fscanf(ptr_file, "%i", &my_data.end[1]);
        printf("Columns %d\n", my_data.Columns);
        printf("Rows %d\n", my_data.rows);
        printf("Start %d , %d\n", my_data.start[0], my_data.start[1]);
        printf("End %d , %d\n", my_data.end[0], my_data.end[1]);
        fclose(ptr_file);
        //Go and allocate space based on dimensions given here.Maybe also fill in Start and end coords here
    }
}

int main() {
    printf("Hello, TEST!\n");
    //int * top =(int*)malloc(sizeof(int));

    struct ReadMaze my_data;
    Read_Size(my_data);
    return 0;
}

