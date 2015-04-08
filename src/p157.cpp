#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF 512

using namespace std;

int mystrlen(char *s) {
    int len = 0;
    while(*s) {
        len++;
        s++;
    }
    return len;
}

void mystrcpy(char *to, char *from) {
    int i = 0;
    do {
	    to[i] = from[i];
    } while (from[i++] != '\0');
}

char* mystrcat(char *dest, char *src) {
	char *original = dest;
    int len = mystrlen(dest);
	dest += len;
    mystrcpy(dest, src);
    return original;
}

int main() {
    char prefix[MAX_BUF] = "Hello ";
    char name[MAX_BUF];

    printf("What is your name? ");
    fgets(name, MAX_BUF, stdin);

    char *final = mystrcat(prefix, name);
    printf("%s", final);
}


