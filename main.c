#include <stdlib.h>
#include "dynarrlib.h"

int main(){
    dynamic_array main_array;
    new_array(&main_array);

    // int* a = malloc(sizeof(int));
    // *a = 10;
    // main_array.stuff[0].data = a;
    // main_array.stuff[0].type = INT_DATA;
    // main_array.size++;

    // char* b = strdup("Hello!");
    // main_array.stuff[1].data = b;
    // main_array.stuff[1].type = STR_DATA;
    // main_array.size++;

    // print_array(&main_array);
    // free_array(&main_array); 

    for (int i = 0; i < 10; i++){
        push(&main_array, "Hello, World!", STR_DATA);
    }

    print_array(&main_array);
    free_array(&main_array);
    print_array(&main_array);



    return 0;

}