#include <stdio.h>

#define MULT(a, b) a + b

int main(int argc, char const *argv[])
{
    int i = 20, j = 30;
    printf("%d\n", MULT(i, j) * MULT(j, i) + MULT(2, 2));
    return 0;
}
