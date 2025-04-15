#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int branch_even_odd(int x) {
    if(x % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}


// x 가 홀수이면 1, 짝수이면 0
int branchless_even_odd(int x) {
    return x & 1;
}



int main() {
    clock_t start, end;
    int *arr = malloc(sizeof(int) *1000000);
    if(!arr) {
        perror("Memory allocation failed.");
        return 1;
    }

    for(int i = 0; i < 1000000; i++) {
        arr[i] = rand();
    }
 
    start = clock();
    for(int i = 0; i < 1000000; i++) {
        branch_even_odd(arr[i]);
    }
    end = clock();
    printf("branch_even_odd: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    for(int i = 0; i < 1000000; i++) {
        branchless_even_odd(arr[i]);
    }
    end = clock();
    printf("branchless_even_odd: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
