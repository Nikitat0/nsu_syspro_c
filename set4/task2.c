#include <assert.h>
#include <stdio.h>
#include <math.h>

unsigned int dividers_number(unsigned int n) {
    assert(n > 0);
    unsigned int c = 0;
    unsigned int sqrt_of_n = sqrt(n);
    for (unsigned int i = 1; i <= sqrt_of_n; i++)
        if(n % i == 0)
            c += 2;
    if (sqrt_of_n * sqrt_of_n == n)
        c -= 1;
    return c;
}

int main() {
    unsigned int n;
    scanf("%u", &n);
    if (n == 0) {
        printf("number mustn't be 0\n");
        return 1;
    }
    printf("%u\n", dividers_number(n));
    return 0;
}
