#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

#define MAX 12
#define COUNTBY 3

int main(int argc, char *argv[]) {
    for(int i = 0; i < (MAX - 1); i += (COUNTBY)) {
        printf("I can count to %d!\n", i);
    }   
}
