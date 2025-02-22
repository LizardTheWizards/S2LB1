#pragma once

typedef struct {
    size_t size;
    void* (*copy)(const void* data);
    void (*destroy)(void* data);
    void (*print)(const void* data);
    int (*compare)(void* el1, void* el2);
} TypeInfo;

extern const TypeInfo INT_TYPE;
extern const TypeInfo STR_TYPE;
