#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int branch_abs(int x){
    return x < 0 ? -x : x;
}

int branchless_abs(int x){
    int mask = x >> 31;
    return (x ^ mask) - mask;
}

int main(){
    int *arr = malloc(sizeof(int) * 1000000);
    if(!arr) {
        perror("malloc failed");
        return 1;
    }

    //랜덤 정수 배열 생성
    srand(time(NULL));
    for(int i = 0; i < 1000000; i++){
        arr[i] = (rand() % 20001) - 10000;
    }

    // 브랜치 버전 
    clock_t start1 = clock();
    long long sum1 = 0;
    for(int i= 0; i <1000000; i++){
        sum1 += branch_abs(arr[i]);
    }

    clock_t end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

    // Branchless Version
    clock_t start2 = clock();
    long long sum2 = 0;
    for(int i = 0; i < 1000000; i++){
        sum2 += branchless_abs(arr[i]);
    }
    clock_t end2 = clock();
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;

    printf("branch_abs time: %f\n", time1);
    printf("branchless_abs time: %f\n", time2);
    free(arr);
    return 0;
}

