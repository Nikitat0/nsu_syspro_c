#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nullCheck(void *ptr) {
    if (ptr == NULL) {
        printf("Out of memory");
        exit(0);
    }
}

const char* trim(const char *str) {
    const char *begin = str;
    const char *end = str + strlen(str) - 1;
    do {
        begin++;
    } while (*begin == ' ');
    do {
        end--;
    } while (*end == ' ');

    char* dst = malloc((end - begin + 2) * sizeof(char));
    char *i = dst;
    for(; begin <= end; begin++) {
        *i = *begin;
        i++;
    }
    begin = 0;
    return dst;
}

int main() {
    const char *str = " to be trimmed  ";
    printf("%s\n", trim(str));
    return 0;
}
