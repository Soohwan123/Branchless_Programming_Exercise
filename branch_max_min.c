#include "stdlib.h"
#include "stdio.h"

//브랜치 함수 -> 성능 느림
int branched_max(int a, int b) {
    return a > b ? a : b;
}

//브랜치리스 함수 -> 성능 빠름
int unbranched_max(int a, int b) {
    return b - ((b - a) & ((b - a) >> 31));
}

//브랜치리스 함수 -> 성능 빠름
int unbranched_min(int a, int b) {
    return a + ((b - a) & ((b - a) >> 31));
}

int main() {
    int a = 6;
    int b = 3;
    printf("%d\n", branched_max(a, b));
    printf("%d\n", unbranched_max(a, b));
    printf("%d\n", unbranched_min(a, b));
    return 0;
}
