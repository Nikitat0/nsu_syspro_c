#include <stdio.h>

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    if(n < 2) {
        printf("%llu isn't prime or composite\n", n);
        return 1;
    }
    printf("%llu is ", n);
    for (unsigned long long d = 2; d <= n / 2; d++)
        if (n % d == 0) {
            printf("composite\n");
            return 0;
        }
    printf("prime\n");
    return 0;
}
