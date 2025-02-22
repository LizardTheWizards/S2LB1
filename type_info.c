#include <string.h>
#include "type_info.h"

void* int_copy(const void* data){
    int* new_data = malloc(sizeof(int));
    *new_data = *(int*)data;
    return new_data;
}

void int_destroy(void* data){
    free(data);
}

void* str_copy(const void* data){
    return strdup((char*)data);
}

void str_destroy(void* data){
    free(data);
}

void int_print(const void* data){
    printf("%d", *(const int*)data);
}

void str_print(const void* data){
    printf("%s", (const char*)data);
}

const TypeInfo INT_TYPE = {
    .size = sizeof(int), 
    .copy = int_copy, 
    .destroy = int_destroy,
    .print = int_print
};

const TypeInfo STR_TYPE = {
    .size = sizeof(char*), 
    .copy = str_copy, 
    .destroy = str_destroy,
    .print = str_print
};
