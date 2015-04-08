#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define MAX_BUF 512

using namespace std;

int main() {
    char *string;
    bool foundspace = false;

    fgets(string, MAX_BUF, stdin);

    while(*string) {
        if(!foundspace && *string == ' ') {
           foundspace = true; 
        } else if (foundspace) {
            cout << *string;
        } 
        string++;
    }
    
    return !foundspace;
}
