#pragma once

typedef struct {
    size_t size;
    void* (*copy)(const void* data);
    void (*destroy)(void* data);
    void (*print)(const void* data);
} TypeInfo;

extern TypeInfo INT_TYPE;
extern TypeInfo STR_TYPE;
