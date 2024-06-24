#include <stdio.h>
#include <string.h>
#include "array.h"

array_int make_int_array(int *arr, size_t len, size_t capacity) {
    if (len > capacity) { 
        printf("ERROR: len: %zu is greater than capacity: %zu", len, capacity); 
        exit(1);
    } 
    if (arr == NULL) { 
        arr = (int*) malloc(sizeof(int) * capacity); 
    } 
    array_int array = { 
        .arr = arr,
        .len = len, 
        .capacity = capacity 
    }; 
    return array; 
}

void realloc_arr(array_int *dst, const size_t new_size, const size_t new_capacity) {
    int* temp = (int*)realloc(dst->arr, new_size);
    if (temp == NULL) {
        free(dst->arr);
        free(temp);
        printf("ERROR: Failed to allocate more memory for an array");
        exit(1);
    }
    dst->arr = temp;
    dst->capacity = new_capacity + CAPACITY_RESERVED;
}

void push_int_arr_array(array_int* dst, const int* src, const size_t items_len) { 
    const size_t total_len = dst->len + items_len; 
    if (total_len > dst->capacity) {
        realloc_arr(dst, sizeof(int) * (total_len + CAPACITY_RESERVED), total_len + CAPACITY_RESERVED);
    }
    memcpy(dst->arr + dst->len, src, items_len * sizeof(int)); 
    dst->len += items_len; 
}

void push_int_array(array_int* dst, const int item) { 
    const size_t total_len = dst->len + 1; 
    if (total_len > dst->capacity) {
        realloc_arr(dst, sizeof(int) * (total_len + CAPACITY_RESERVED), total_len + CAPACITY_RESERVED);
    }
    dst->arr[dst->len] = item; 
    dst->len += 1; 
}

void push_array_int_arr_array(array_int* dst, array_int* src) { 
    const size_t total_len = dst->len + src->len; 
    if (total_len > dst->capacity) {
        realloc_arr(dst, sizeof(int) * (total_len + CAPACITY_RESERVED), total_len + CAPACITY_RESERVED);
    }
    memcpy(dst->arr + dst->len, src->arr, src->len * sizeof(int)); 
    dst->len += src->len; 
}

bool pop_int_array(array_int* dst, int* result) {
    if (dst->len == 0) {
        return false;
    }

    *result = dst->arr[--dst->len];
    return true;
}

bool slice_int_array(array_int* src, array_int* dst, int start, int end) {

}

void print_int_array(array_int* arr) { 
    for (int i = 0; i < arr->len; i++) { 
        switch(sizeof(int)) { 
            case sizeof(int): 
                printf("%d\n", arr->arr[i]);
                break; 
        }
    } 
}
