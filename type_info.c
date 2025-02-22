#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
    const char* original_str = (const char*)data;
    size_t len = strlen(original_str) + 1;
    char* new_data = malloc(len);
    strcpy(new_data, original_str);
    return new_data;
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

int compare_int(void* el1, void* el2){
    int int_el1 = *(int*)el1;
    int int_el2 = *(int*)el2;
    return (int_el1 < int_el2);
}

int compare_str(void* el1, void* el2){
    char* str_el1 = (char*)el1;
    char* str_el2 = (char*)el2;
    return (strcmp(str_el1, str_el2) < 0);
}

const TypeInfo INT_TYPE = {
    .size = sizeof(int), 
    .copy = int_copy, 
    .destroy = int_destroy,
    .print = int_print,
    .compare = compare_int
};

const TypeInfo STR_TYPE = {
    .size = sizeof(char*), 
    .copy = str_copy, 
    .destroy = str_destroy,
    .print = str_print,
    .compare = compare_str
};
