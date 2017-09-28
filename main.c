#include <stdio.h>
#include <malloc.h>

int main() {
    printf("Hello, TEST!\n");
    int my_int;
    my_int = 3;
    int * top =(int*)malloc(sizeof(int));
    top[0] = my_int;
    printf("Num = %d\n",*top);
    return 0;
}