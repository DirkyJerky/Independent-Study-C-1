#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

int main() {
    char *one = "one";
    char *two = "two";
    char *three = "three";


    char *s1 = one;
    char *s2 = two;
    char *s3 = three;
    char *swap = NULL;

    for(int i = 6; i > 0; i--) {
        printf("%s %s %s\n", s1, s2, s3);
        if(i%2) {
           swap = s1;
           s1 = s2;
           s2 = swap;
        } else {
            swap = s2;
            s2 = s3;
            s3 = swap;
  
        }
    }    
}

