#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int *findSubArr(int arr1[], size_t size1, int arr2[], size_t size2) {
    assert(size1 >= size2);
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

int main() {
    int arr1[] = {0, 1, 8, 7, 4, 1, 8, 7, 6};
    int arr2[] = {8, 7};
    if (findSubArr(arr1, 9, arr2, 2) == arr1 + 2) {
        printf("found\n");
        return 0;
    }
    printf("error\n");
    return 1;
}
