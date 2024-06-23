#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>

#define CAPACITY_RESERVED 10

#define DECLARE_ARRAY_TYPE(type) \
typedef struct { \
    type* arr; \
    size_t len; \
    size_t capacity; \
} array_##type; \
\
array_##type make_##type##_array(type *arr, size_t len, size_t capacity); \
\
void push_##type##_arr_array(array_##type* dst, const type* src, const size_t items_len); \
void push_##type##_array(array_##type* dst, const type item); \
void push_array_##type##_arr_array(array_##type* dst, array_##type* src); \
\
void print_##type##_array(array_##type* arr);

DECLARE_ARRAY_TYPE(int);
DECLARE_ARRAY_TYPE(float);

#endif //ARRAY_H
