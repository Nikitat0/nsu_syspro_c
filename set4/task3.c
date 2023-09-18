#include <assert.h>
#include <stdio.h>
#include <math.h>

unsigned int gcd(unsigned int a, unsigned int b) {
    assert(a > 0);
    assert(b > 0);
    while (b != 0) {
        unsigned int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    unsigned int a, b;
    scanf("%u", &a);
    scanf("%u", &b);
    if (a == 0 || b == 0) {
        printf("both of numbers mustn't be 0\n");
        return 1;
    }
    printf("%u\n", gcd(a, b));
    return 0;
}
