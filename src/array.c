#include "array.h"

#include <stdio.h>
#include <string.h>

#define DEFINE_ARRAY_TYPE(type) \
\
array_##type make_##type##_array(type *arr, size_t len, size_t capacity) { \
    if (len > capacity) { \
        printf("ERROR: len: %zu is greater than capacity: %zu", len, capacity); \
        exit(1);\
    } \
    if (arr == NULL) { \
        arr = (type*) malloc(sizeof(type) * capacity); \
    } \
    array_##type array = { \
        .arr = arr, \
        .len = len, \
        .capacity = capacity \
    }; \
    return array; \
} \
\
void push_##type##_arr_array(array_##type* dst, const type* src, const size_t items_len) { \
    const size_t total_len = dst->len + items_len; \
    if (total_len > dst->capacity) { \
        dst->arr = (type*)realloc(dst->arr, sizeof(type) * (total_len + CAPACITY_RESERVED)); \
        dst->capacity = total_len + CAPACITY_RESERVED; \
    } \
    memcpy(dst->arr + dst->len, src, items_len * sizeof(type)); \
    dst->len += items_len; \
}\
void push_##type##_array(array_##type* dst, const type item) { \
    const size_t total_len = dst->len + 1; \
    if (total_len > dst->capacity) { \
        dst->arr = (type*)realloc(dst->arr, sizeof(type) * (total_len + CAPACITY_RESERVED)); \
        dst->capacity = total_len + CAPACITY_RESERVED; \
    } \
    dst->arr[dst->len] = item; \
    dst->len += 1; \
}\
\
void push_array_##type##_arr_array(array_##type* dst, array_##type* src) { \
    const size_t total_len = dst->len + src->len; \
    if (total_len > dst->capacity) { \
        dst->arr = (type*)realloc(dst->arr, sizeof(type) * (total_len + CAPACITY_RESERVED)); \
        dst->capacity = total_len + CAPACITY_RESERVED; \
    } \
    memcpy(dst->arr + dst->len, src->arr, src->len * sizeof(type)); \
    dst->len += src->len; \
}\
void print_##type##_array(array_##type* arr) { \
    for (int i = 0; i < arr->len; i++) { \
        switch(sizeof(type)) { \
            case sizeof(int): \
                printf("%d\n", arr->arr[i]); \
                break; \
        }\
    } \
}

DEFINE_ARRAY_TYPE(int);
