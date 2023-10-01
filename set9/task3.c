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

int *findSubArr(int arr1[], size_t size1, int arr2[], size_t size2) {
    // assert(size1 >= size2);
    for (size_t i = 0; i < size1; i++) {
        size_t j = 0;
        for(; j < size2; j++) 
            if (arr1[i + j] != arr2[j])
                break;
        if (j == size2)
            return arr1 + i;
    }
    return NULL;
}

void removeSubArr(int arr1[], size_t *size1, int arr2[], size_t size2) {
    assert(*size1 >= size2);
    int *entry;
    while((entry = findSubArr(arr1, *size1, arr2, size2)) != NULL) {
        for(size_t i = entry - arr1 + size2; i <= *size1; i++)
            arr1[i - size2] = arr1[i];
        *size1 -= size2;
    }
};

int main() {
    int arr1[] = {0, 1, 2, 3, 1, 2, 4};
    size_t size1 = 7;
    int arr2[] = {1, 2};
    removeSubArr(arr1, &size1, arr2, 2);
    printArr(arr1, size1);
}
