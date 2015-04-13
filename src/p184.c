#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF 512

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: <password>\n");
        exit(1);
    }

    char *password = "password";
    
    char *entered = argv[1];

    if(strcmp(password, entered)) {
        printf("Access denied\n");
    } else {
        printf("Access permitted\n");
    }
}


