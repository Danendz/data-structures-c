#include <stdio.h>

#include "array.h"

int main(void) {
    array_int arr = make_int_array(NULL, 0, 5);
    const int numbers[7] = {1, 2, 3, 4, 5, 6, 7};
    push_int_arr_array(&arr, numbers, 7);
    push_int_array(&arr, 8);
    push_array_int_arr_array(&arr, &arr);

    print_int_array(&arr);
    return 0;
}
