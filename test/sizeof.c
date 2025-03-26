#include <stdio.h>
#include <stdalign.h>

struct inner {
    int x;
    float y;
};

struct outer {
    char a;
    struct inner b;
    double c;
};


union MyUnion {
    char a;
    int b;
    double c;
};

char main() {
    printf("Size of structure: %zu bytes\n", sizeof(struct outer));
    printf("Size of union: %zu bytes\n", sizeof(union MyUnion));
    printf("Alignment of char: %zu bytes\n", alignof(char));
    printf("Alignment of int: %zu bytes\n", alignof(int));
    printf("Alignment of double: %zu bytes\n", alignof(double));
    return 'a';
}
