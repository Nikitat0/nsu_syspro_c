#include <stdio.h>

int main() {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    printf("%d + %d = %d\n", x, y, x + y);
    printf("%d - %d = %d\n", x, y, x - y);
    printf("%d * %d = %d\n", x, y, x * y);
    printf("%d == %d = %d\n", x, y, x == y);
    printf("%d != %d = %d\n", x, y, x != y);
    printf("%d < %d = %d\n", x, y, x < y);
    printf("%d > %d = %d\n", x, y, x > y);
    printf("%d <= %d = %d\n", x, y, x <= y);
    printf("%d >= %d = %d\n", x, y, x >= y);
    printf("%d && %d = %d\n", x, y, x && y);
    printf("%d || %d = %d\n", x, y, x || y);
    printf("%d & %d = %d\n", x, y, x & y);
    printf("%d | %d = %d\n", x, y, x | y);
    printf("%d ^ %d = %d\n", x, y, x ^ y);
    printf("%d << %d = %d\n", x, y, x << y);
    printf("%d >> %d = %d\n", x, y, x >> y);

    if (y == 0) {
        printf("Division by zero and remainder of such operation is undefined\n");
    } else {
        printf("%d / %d = %d\n", x, y, x / y);
        printf("%d %% %d = %d\n", x, y, x % y);
    }

    return 0;
}
