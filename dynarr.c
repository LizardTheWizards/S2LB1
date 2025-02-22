#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynarrlib.h"

void new_array(dynamic_array* arr){
    arr->stuff = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void free_array(dynamic_array* arr){
    for (size_t i = 0; i < arr->size; i++){
        if (arr->stuff[i].type == STR_DATA){
            free(arr->stuff[i].data);
        }
    }
    free(arr->stuff);
    arr->stuff = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void print_array(dynamic_array* arr){
    printf("Array (size: %zu, capacity: %zu):\n", arr->size, arr->capacity);
    for (size_t i = 0; i < arr->size; i++){
        if (arr->stuff[i].type == INT_DATA){
            printf("[%Iu] INT: %d\n", i, *(int*)arr->stuff[i].data);
        }
        else if (arr->stuff[i].type == STR_DATA) {
            printf("[%Iu] STR: %s\n", i, (char*)arr->stuff[i].data);
        }
    }
}

void push(dynamic_array* arr, void* value, data_type type){
    if (arr->capacity == 0){ //если первый элемент
        arr->capacity++;
        arr->stuff = malloc(sizeof(element));
    }
    else if(arr->size == arr->capacity){ //если массив - полный
        arr->capacity++;
        arr->stuff = realloc(arr->stuff, arr->capacity * sizeof(element));
    }

    if (!arr->stuff){
        printf("Memory allocation error!");
    }

    arr->stuff[arr->size].type = type;

    if (type == INT_DATA){
        arr->stuff[arr->size].data = malloc(sizeof(int));
        if (!arr->stuff[arr->size].data){
            printf("Memory allocation error!");
        }
        *(int*)arr->stuff[arr->size].data = *(int*)value;
    }
    else if (type == STR_DATA){
        arr->stuff[arr->size].data = strdup((char*)value);
        if (!arr->stuff[arr->size].data){
            printf("Memory allocation error!");
        }
    }

    arr->size++;
}

void swap(dynamic_array* arr, int index1, int index2){
    if (index1 > arr->size || index2 > arr->size){
        printf("")
    }
}