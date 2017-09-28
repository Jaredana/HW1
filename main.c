
#include "input.h"

void Read_Size(struct ReadMaze my_data) {
    FILE *ptr_file = fopen("maze2.txt", "r");

    if (!ptr_file)
    {
        printf("Oh no! % s\n", strerror(errno));
        return; //Fail
    }
    if(fscanf(ptr_file, "%i," , &my_data.Columns)) {
        fscanf(ptr_file, "%i,", &my_data.rows);
        printf("Columns %d\n", my_data.Columns);
        printf("Rows %d\n", my_data.rows);
        //Go and allocate space based on dimensions given here.Maybe also fill in Start and end coords here
    }
    fclose(ptr_file);

}

int main() {
    printf("Hello, TEST!\n");
    //int * top =(int*)malloc(sizeof(int));

    struct ReadMaze my_data;
    Read_Size(my_data);
    return 0;
}

