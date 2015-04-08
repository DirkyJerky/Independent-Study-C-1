#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF 512

using namespace std;

int factorial(int max) {
    if(max <= 0) {
        return 0;
    } else if (max == 1) {
        return 1;
    } else {
        return max * factorial(max - 1);
    }
    
}


int main() {
    int max;

    printf("Please a number: ");

    scanf("%d", &max);

    printf("factorial(%d) -> %d\n", max, factorial(max));
}


