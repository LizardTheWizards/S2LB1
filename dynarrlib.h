#pragma once


typedef enum {
    INT_DATA,
    STR_DATA
}data_type;

typedef struct {
    void* data;
    data_type type;
}element;

typedef struct {
    element* stuff;
    size_t size; //количество занятых элементов
    size_t capacity; //всего элементов
}dynamic_array;

void new_array(dynamic_array* arr);
void free_array(dynamic_array* arr);
void print_array(dynamic_array* arr);
void push(dynamic_array* arr, void* value, data_type type);
