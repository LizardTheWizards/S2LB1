#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynarrlib.h"
#include "type_info.h"

int main(){
    dynamic_array arr1;
    new_array(&arr1);
    dynamic_array arr2;
    new_array(&arr2);

    int a = 42, b = 17, c = 99, d = 5;
    push(&arr1, &a, &INT_TYPE);
    push(&arr1, &b, &INT_TYPE);
    push(&arr1, &c, &INT_TYPE);
    push(&arr1, &d, &INT_TYPE);

    char *s1 = strdup("Cherry"), *s2 = strdup("Apple"), *s3 = strdup("Banana");
    push(&arr2, s1, &STR_TYPE);
    push(&arr2, s2, &STR_TYPE);
    push(&arr2, s3, &STR_TYPE);

    printf("Array 1 before sorting:\n");
    print_array(&arr1);

    printf("Going for sort\n");
    mixed_sort(&arr1);
    printf("Sorted\n");

    printf("Array 1 after sorting:\n");
    print_array(&arr1);

    printf("Array 2 before sorting:\n");
    print_array(&arr2);

    mixed_sort(&arr2);

    printf("Array 2 after sorting:\n");
    print_array(&arr2);

    free_array(&arr1);
    free_array(&arr2);

    return 0;

}