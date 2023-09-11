#include <stdio.h>

int main() {
    unsigned long n;
    scanf("%lu", &n);
    for(unsigned long i = 0; i < n * n; i++) {
        printf("%lu", i);
        printf("%c", (i + 1) % n == 0 ? '\n' : ' ');
    }
    printf("\n");
    return 0;
}
