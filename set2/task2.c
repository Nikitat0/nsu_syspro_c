#include <stdio.h>

int main() {
    unsigned short year;
    scanf("%hu", &year);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        printf("%d is a leap year\n", year);
    else
        printf("%d isn't a leap year\n", year);
    return 0;
}
