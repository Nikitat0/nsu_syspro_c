#include <stdio.h>

int main() {
    unsigned long n;
    scanf("%lu", &n);
    
    unsigned long line = 1;
    for(unsigned long i = 0; i < n * (n + 1) / 2; i++) {
        printf("%lu", i);
        if ((i + 1) == line + (line * (line - 1)) / 2) {
            line++;
            printf("\n");
        } else
            printf(" ");
    }
    return 0;
}
