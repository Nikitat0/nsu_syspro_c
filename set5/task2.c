#include <stdio.h>

void evil_scanf(int *p0, int *p1, int *p2) {
    int n0, n1, n2;
    scanf("%d", &n0);
    scanf("%d", &n1);
    scanf("%d", &n2);
    int p0_old = *p0, p1_old = *p1, p2_old = *p2;
    *p0 = n0;
    if (n0 > 0) {
        *p1 = n1;
        *p2 = n2;
    } else {
        *p1 = p0_old;
        *p2 = n0 * n1 * n2 * p1_old * p2_old;
    }
}

int main() {
    int a = 0, b = 1, c = 2;
    evil_scanf(&a, &b, &c);
    printf("%d %d %d \n", a, b, c);
    return 0;
}
