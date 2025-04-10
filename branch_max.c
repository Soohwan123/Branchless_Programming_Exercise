#include "stdlib.h"
#include "stdio.h"

int branched_max(int a, int b) {
    return a > b ? a : b;
}

int unbranched_max(int a, int b) {
    return a + ((b - a) & ((b - a) >> 31));
}

int main() {
    int a = 6;
    int b = 3;
    printf("%d\n", branched_max(a, b));
    printf("%d\n", unbranched_max(a, b));
    
    return 0;
}
