#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

int menu() {
    printf("Card Catalog:\n");
    printf("\n");
    printf("1: Enter\n");
    printf("2: Search by Author\n");
    printf("3: Search by Title\n");
    printf("4: Quit\n");
    printf("\n");
    printf(":");

    int code;
    scanf("%d", &code);

    // Consume
    while(getchar() != '\n') {}

    if (!(1 <= code && code <= 4)) {
        return 0;
    }
    return code;
}

void mEnter() {
    char name[MAX_BUF];
    char author[MAX_BUF];
    char publisher[MAX_BUF];
    
    printf("Enter blank name to end.\n");
    while(true) {
        printf("Name: ");
        fgets(name, MAX_BUF, stdin);

        // If name is blank ("\n\0")
        if(!(name[1])) {
            break;
        }

        printf("Author: ");
        fgets(author, MAX_BUF, stdin);

        printf("Publisher: ");
        fgets(publisher, MAX_BUF, stdin);

        // Do stuff with data
    }
}

int main(int argc, char *argv[]) {
    int opt = menu();
    switch(opt) {
        case 0:
            printf("Wrong Option.\n");    
            break;
        
        case 1:
            mEnter();
            break;

        case 2:
            printf("NOOP.\n");    
            break;

        case 3:
            printf("NOOP.\n");    
            break;

        case 4:
            printf("NOOP.\n");    
            break;
    }
}
