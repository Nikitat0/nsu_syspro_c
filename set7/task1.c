#include <stdio.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    // # x ->
    // y
    // |
    // \/
    int arr[4][4];
    for(size_t y = 0; y < 4; y++)
        for(size_t x = 0; x < 4; x++)
            scanf("%d", &arr[x][y]);

    for(size_t y = 0; y < 3; y++)
        for(size_t x = y + 1; x < 4; x++)
            swap(&arr[x][y], &arr[y][x]);

    for(size_t y = 0; y < 4; y++)
        for(size_t x = 0; x < 4; x++)
            printf("%d%c", arr[x][y], x == 3 ? '\n' : ' ');
    return 0;
}
