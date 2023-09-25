#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i + 1 == size)
            printf("\n");
        else
            printf(" ");
    }
}

void revertArr(int arr[], size_t size) {
    for(size_t i = 1; i <= (size - i); i++) {
        int temp = arr[i - 1];
        arr[i - 1] = arr[size - i];
        arr[size - i] = temp;
    }
}

int maxInArr(int arr[], size_t size) {
    int max = *arr;
    for (size_t i = 1; i < size; i++) 
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int findInArr(int arr[], size_t size, int x) {
    for (size_t i = 0; i < size; i++) 
        if (arr[i] == x)
            return i;
    return -1;
}

void extractDigit(int arr[], size_t size, unsigned int n) {
    assert(size >= 10);
    int i = 0;
    for(; n != 0; i++) {
        arr[i] = n % 10;
        n /= 10;
    }
    revertArr(arr, i);
}

int compareArrays(int arr1[], size_t size1, int arr2[], size_t size2) {
    for (size_t i = 0; i < size1 && i < size2; i++) {
        if (arr1[i] == arr2[i])
            continue;
        return arr1[i] < arr2[i] ? -1 : 1;
    }
    if (size1 == size2)
        return 0;
    else if(size1 < size2)
        return -1;
    else
        return 1;
}

void nullCheck(void *ptr) {
    if (ptr == NULL) {
        printf("Out of memory");
        exit(0);
    }
}

int* own_realloc(int arr[], size_t size, size_t new_size) {
    assert(size <= new_size);
    int *new_arr = malloc(new_size * sizeof(int));
    nullCheck(new_arr);
    for(size_t i = 0; i < size; i++)
        new_arr[i] = arr[i];
    free(arr);
    return new_arr;
}

int main() {
    int *arr = (int*) malloc(sizeof(int));
    size_t size = 0;
    size_t capacity = 1;
    nullCheck(arr);
    for (;;) {
        int a;
        scanf("%d", &a);
        if (a == 0)
            break;
        if (size == capacity) {
            arr = own_realloc(arr, capacity, capacity * 2);
            capacity *= 2;
        }
        arr[size++] = a;
    }

    printf("Max element is %d\n", maxInArr(arr, 10));
    printf("1 found by index %d\n", findInArr(arr, 10, 1));
    revertArr(arr, 10);
    printf("Reverted array:\n");
    printArr(arr, 10);
    revertArr(arr, 10);

    int d_arr[10];
    for (size_t i = 0; i < 10; i++)
        d_arr[i] = 0;

    unsigned int a;
    printf("Type number: ");
    scanf("%d", &a);
    extractDigit(d_arr, 10, a);
    printf("Your number as array of digits: \n");
    printArr(d_arr, 10);

    printf("Result of comparison: %d\n", compareArrays(arr, 10, d_arr, 10));
    free(arr);
    return 0;
}
