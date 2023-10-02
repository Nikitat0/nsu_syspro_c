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

void scanArr(int *arr[], size_t *size, size_t *capacity) {
    *arr = malloc(1 * sizeof(int));
    *size = 0;
    *capacity = 1;
    nullCheck(*arr);

    for (;;) {
        int e;
        scanf("%d", &e);
        if (e == 0)
            break;
        if (size == capacity) {
            *arr = realloc(*arr, *capacity *= 2 * sizeof(int));
            nullCheck(*arr);
        }
        (*arr)[*size] = e;
        (*size)++;
    }
}

int main() {
    int *arr;
    size_t size;
    size_t capacity;
    scanArr(&arr, &size, &capacity);
    printArr(arr, size);
}
