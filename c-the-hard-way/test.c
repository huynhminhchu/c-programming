#include <stdio.h>
#include <stddef.h>

struct P1 {
    short i;
    int c;
    int *j;
    short *d;
};

struct P2 {
    int i[2];
    char c[8];
    short s[4];
    long *j;
};

struct P3 {
    long w[2];
    int *c[2];
};

struct P4 {
    char w[16];
    char *c[2];
};

struct P5 {
    struct P4 a[2];
    struct P1 t;
};

struct P6{
    int *a;
    float b;
    char c;
    short d;
    long e;
    double f;
    int g;
    char *h;
};

int main() {
    struct P1 p1;
    printf("Size of short P1: %zu bytes\n", sizeof(p1));

    printf("%zu\n", offsetof(struct P1, i));
    printf("%zu\n", offsetof(struct P1, c));
    printf("%zu\n", offsetof(struct P1, j));
    printf("%zu\n", offsetof(struct P1, d));

    struct P2 p2;
    printf("Size of short P2: %zu bytes\n", sizeof(p2));

    printf("%zu\n", offsetof(struct P2, i));
    printf("%zu\n", offsetof(struct P2, c));
    printf("%zu\n", offsetof(struct P2, s));
    printf("%zu\n", offsetof(struct P2, j));

    struct P3 p3;
    printf("Size of short P3: %zu bytes\n", sizeof(p3));
    printf("%zu\n", offsetof(struct P3, w));
    printf("%zu\n", offsetof(struct P3, c));

    struct P4 p4;
    printf("Size of short P4: %zu bytes\n", sizeof(p4));
    printf("%zu\n", offsetof(struct P4, w));
    printf("%zu\n", offsetof(struct P4, c));

    struct P5 p5;
    printf("Size of short P4: %zu bytes\n", sizeof(p5));
    printf("%zu\n", offsetof(struct P5, a));
    printf("%zu\n", offsetof(struct P5, t));

    struct P6 p6;
    printf("Size of short P6: %zu bytes\n", sizeof(p6));
    printf("%zu\n", offsetof(struct P6, a));
    printf("%zu\n", offsetof(struct P6, b));
    printf("%zu\n", offsetof(struct P6, c));
    printf("%zu\n", offsetof(struct P6, d));
    printf("%zu\n", offsetof(struct P6, e));
    printf("%zu\n", offsetof(struct P6, f));
    printf("%zu\n", offsetof(struct P6, g));
    printf("%zu\n", offsetof(struct P6, h));
    return 0;
}