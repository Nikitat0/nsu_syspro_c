#include <stdio.h>

void foo() {
    int some_local_var;
    printf("Addr of some_local_var is %p\n", &some_local_var);
    return;
}

void bar() {
    foo();
    return;
}

int main() {
    foo();
    bar();
    return 0;
}
