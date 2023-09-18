#include <assert.h>
#include <stdio.h>

int is_prime(unsigned long long n) {
    assert(n > 1);
    for (unsigned long long d = 2; d <= n / 2; d++)
        if (n % d == 0) {
            return 0;
        }
    return 1;
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    if(n < 2) {
        printf("%llu isn't prime or composite\n", n);
        return 1;
    }
    printf("%llu is ", n);
    if (is_prime(n))
        printf("prime\n");
    else
        printf("composite\n");
    return 0;
}
