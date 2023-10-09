#include <stdio.h>
#include <string.h>

int isPalindrome(const char *str) {
    const char *begin = str - 1;
    const char *end = str + strlen(str);
    while(begin <= end) {
        do {
            begin++;
        } while (*begin == ' ');
        do {
            end--;
        } while (*end == ' ');
        if (*begin != *end)
            return 0;
    }
    return 1;
}

int main() {
    const char *a = "no palindrome";
    const char *b = "a ba ";
    if (!isPalindrome(a))
        printf("\"%s\" is not palindrome\n", a);
    if (isPalindrome(b))
        printf("\"%s\" is palindrome\n", b);
    return 0;
}
