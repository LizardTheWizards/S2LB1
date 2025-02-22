#pragma once
#include "type_info.h"


typedef struct {
    void* data;
    const TypeInfo* type;
}element;

typedef struct {
    element* stuff;
    size_t size; //количество занятых элементов
    size_t capacity; //всего элементов
}dynamic_array;

void new_array(dynamic_array* arr);
void free_array(dynamic_array* arr);
void print_array(const dynamic_array* arr);

void push(dynamic_array* arr, const void* value, const TypeInfo* type);
void remove(dynamic_array* arr, size_t index);
// void swap(dynamic_array* arr, size_t index1, size_t index2);
