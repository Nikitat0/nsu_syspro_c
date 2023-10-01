#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void nullCheck(void *ptr) {
    if (ptr == NULL) {
        printf("Out of memory");
        exit(0);
    }
}

void printArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i + 1 == size)
            printf("\n");
        else
            printf(" ");
    }
}

void concat(int arr1[], size_t size1, int arr2[], size_t size2, int *arr3[], size_t *size3) {
    *size3 = size1 + size2;
    *arr3 = malloc(*size3 * sizeof(int));
    nullCheck(*arr3);
    for(size_t i = 0; i < size1; i++)
        (*arr3)[i] = arr1[i];
    for(size_t i = 0; i < size2; i++)
        (*arr3)[size1 + i] = arr2[i];
}

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 0};
    int *arr3;
    size_t size;
    concat(arr1, 5, arr2, 5, &arr3, &size);
    printArr(arr3, size);
}
