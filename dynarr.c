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
        arr->stuff[i].type->destroy(arr->stuff[i].data);
    }
    free(arr->stuff);
    arr->stuff = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

void print_array(const dynamic_array* arr){
    printf("Array (size: %zu, capacity: %zu):\n", arr->size, arr->capacity);
    for (size_t i = 0; i < arr->size; i++){
        printf("[");
        arr->stuff[i].type->print(arr->stuff[i].data);
        printf("]\n");
    }
}

void push(dynamic_array* arr, const void* value, const TypeInfo* type){
    if (arr->size == arr->capacity){
        arr->capacity++;
        arr->stuff = realloc(arr->stuff, arr->capacity * sizeof(element));
    }

    arr->stuff[arr->size].type = type;
    arr->stuff[arr->size].data = type->copy(value);
    arr->size++;
}

void swap(element* el1, element* el2){
    if (el1 == el2){
        return;
    }
    void* temp = malloc(el1->type->size);
    if (!temp){
        printf("Error of memory aalocation");
    }

    size_t tsize = el1->type->size;
    memcpy(temp, el1->data, strlen(el1->data) + 1);
    memcpy(el1->data, el2->data, strlen(el2->data) + 1);
    printf("Element 1 is %s\n", (char*)el1->data);
    memcpy(el2->data, temp, strlen(temp) + 1);
    printf("Element 2.2 is %s\n", (char*)el2->data);

    free(temp);
}

void mixed_sort(dynamic_array* arr){
    size_t size = arr->size;
    for (size_t i = 0; i < size - 1; i++){
        for(size_t j = 0; j < size - 1 - i; j++){
            if(arr->stuff[j].type->compare(arr->stuff[j + 1].data, arr->stuff[j].data)){
                swap(&arr->stuff[j], &arr->stuff[j + 1]);
            }
            // if(arr->stuff[size - j].type->compare(arr->stuff[size - j - 1].data, arr->stuff[size - j].data)){
            //     swap(&arr->stuff[size - j - 1], &arr->stuff[size- j]);
            // }
        }
    }
}