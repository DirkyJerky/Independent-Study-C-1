#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF 512

double avg(float *nums) {
    double total = 0.0;
    for(int i = 0; i < 10; i++) {
        total += nums[i];
    } 
    return total / 10.0;
}

int main() {
    float nums[10];

    printf("Please enter 10 numbers: ");

    for(int i = 0; i < 10; i++) {
        scanf("%f", &nums[i]);
    } 

    printf("Average is: %.3f\n", avg(nums));
}


