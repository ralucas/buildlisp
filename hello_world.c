#include <stdio.h>

int test(int n) {
    while (n > 0) {
        puts("Hello World!");
        n -= 1;
    }
    return 0;
}

int main(int argc, char** argv) {
    test(5);
}

