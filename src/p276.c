#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

int main(int argc, char *argv[]) {
    struct s_type {
        char ch;
        float d;
        int i;
        char str[80];
        double balance;
    };   

    struct s_type s_var = {'f', 0.314, 5, "Hello World!", 3140000000000};
    
    printf("%c, %f, %d, %s, %f\n", s_var.ch, s_var.d, s_var.i, s_var.str, s_var.balance);
}
