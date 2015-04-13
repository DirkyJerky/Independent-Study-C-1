#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

int main() {
    char *string;
    bool foundspace = false;

    fgets(string, MAX_BUF, stdin);

    while(*string) {
        if(!foundspace && *string == ' ') {
           foundspace = true; 
        } else if (foundspace) {
            printf("%c", *string);
        } 
        string++;
    }
    
    return !foundspace;
}
