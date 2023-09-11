#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    if(n < 2) {
        printf("%llu isn't prime or composite\n", n);
        return 1;
    }
    char *isComposite = calloc(n + 1, sizeof(char));
    for(unsigned long long p = 2; p <= n; p++) {
        if (isComposite[p])
            continue;
        printf("%llu\n", p);
        for (unsigned long long i = p * p; i <= n; i += p)
            isComposite[i] = 1;
    }
    return 0;
}
