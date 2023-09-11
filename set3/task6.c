#include <stdio.h>

unsigned long sum_digits(unsigned long n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    unsigned long l, r;
    scanf("%lu", &l);
    scanf("%lu", &r);
    if (l > r) {
        printf("L should be less than R");
        return 1;
    }

    if (l < 100000)
        l = 100000;
    if (r > 999999)
        r = 999999;

    for(unsigned long i = l; i <= r; i++)
        if (sum_digits(i / 1000) == sum_digits(i % 1000))
            printf("%lu\n", i);

    return 0;
}
