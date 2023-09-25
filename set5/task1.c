#include <stdio.h>

void foo() {
    int some_local_var;
    printf("Addr of some_local_var is %p\n", &some_local_var);
}

void bar() {
    foo();
}

int main() {
    foo();
    bar();
    return 0;
}
