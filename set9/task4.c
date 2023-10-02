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

void newTriangleArray(size_t rows, int **arr[], size_t *size) {
    assert(rows > 0);
    *arr = malloc(rows * sizeof(int**));
    nullCheck(*arr);
    for (size_t i = 0; i < rows; i++) {
        (*arr)[i] = malloc((i + 1) * sizeof(int*));
        nullCheck((*arr)[i]);
    }
    *size = rows;
}

void pascalTriangle(int *arr[], size_t size) {
    assert(size > 0);
    for (size_t i = 0; i < size; i++) {
        arr[i][0] = 1;
        arr[i][i] = 1;
        for(size_t j = 1; j < i; j++)
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
    }
}

void printTriangleArray(int *arr[], size_t size) {
    for (size_t i = 0; i < size; i++)
        printArr(arr[i], i + 1);
}

int main() {
    int **arr;
    size_t size;
    newTriangleArray(5, &arr, &size);
    pascalTriangle(arr, size);
    printTriangleArray(arr, size);
}
