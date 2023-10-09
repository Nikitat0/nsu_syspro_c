#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nullCheck(void *ptr) {
    if (ptr == NULL) {
        printf("Out of memory");
        exit(0);
    }
}

const char** split(const char *str, size_t *size, size_t *capacity) {
    const char **splitted = malloc(sizeof(const char*));
    nullCheck(splitted);
    *size = 0;
    *capacity = 1;

    for (const char *i = str; *i != 0; i++) {
        if (*i == ' ')
            continue;
        
        const char *j = i;
        while (*j != ' ' && *j != 0)
            j++;

        char *element = malloc((j - i) * sizeof(char));
        char *k = element;
        for (; i < j; i++) {
            *k = *i;
            k++;
        }
        *k = 0;

        nullCheck(element);
        if (*size == *capacity) {
            splitted = realloc(splitted, *capacity *= 2 * sizeof(char));
            nullCheck(splitted);
        }
        splitted[*size] = element;
        (*size)++;
    }

    return splitted;
}

int main() {
    const char *str = " to be  splitted  ";
    size_t size;
    size_t capacity;
    const char **splitted = split(str, &size, &capacity);
    for (size_t i = 0; i < size; i++)
        printf("%s\n", splitted[i]);
    return 0;
}
