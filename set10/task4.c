#include <assert.h>
#include <limits.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nullCheck(void *ptr) {
    if (ptr == NULL) {
        printf("Out of memory");
        exit(0);
    }
}

void exitOrJump(int errorCode, jmp_buf *buf) {
    if (buf != NULL)
        longjmp(*buf, errorCode);
    exit(errorCode);
}

// Error codes:
// 1: Overflow
// 2: Invalid symbol
int s2i(const char *src, unsigned int base, jmp_buf *buf) {
    assert(base <= 16);

    int sign = 1;
    if (*src == '-') {
        sign = -1;
        src++;
    }

    char* valid_symbols= calloc(16, sizeof(char));
    nullCheck(valid_symbols);
    char i = 0;
    for (; i < base && i < 10; i++)
        valid_symbols[i] = '0' + i;
    for (; i < base; i++)
        valid_symbols[i] = 'A' + i - 10;

    long long dst = 0;
    for(const char *i = src; *i != 0; i++) {
        char* digit = strchr(valid_symbols, *i);
        if (digit == NULL)
            exitOrJump(2, buf);
        dst *= base;
        dst += digit - valid_symbols;
        if (INT_MAX < dst || dst < INT_MIN)
            exitOrJump(1, buf);
    }
    dst *= sign;
    return dst;
}

int main() {
    jmp_buf buf;
    setjmp(buf);
    printf("-1A (base 10) = %d\n", s2i("-1A", 11, &buf));
    printf("33 (base 4) = %d\n", s2i("33", 4, &buf));

    int errorCode = setjmp(buf);
    if (errorCode == 0)
        s2i("4294967297", 10, &buf);
    else if (errorCode == 1) {
        printf("Overflow error\n");
    }

    errorCode = setjmp(buf);
    if (errorCode == 0)
        s2i("_cringe_", 10, &buf);
    else if (errorCode == 2) {
        printf("Invalid symbol error\n");
    }

    return 0;
}
