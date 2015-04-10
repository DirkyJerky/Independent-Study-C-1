#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

using namespace std;

FILE *catalog_f;

char **name;
char **author;
char **publisher;
int numBooks = 0;

void consumeLine() {
    while(getchar() != '\n') {}
}


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

    consumeLine();
    if (!(1 <= code && code <= 4)) {
        return 0;
    }
    return code;
}

int writeCatFile() {
    for(int i = 0; i < numBooks; i++) {
        fputs(name[i], catalog_f); fputc('\n', catalog_f); 
        fputs(author[i], catalog_f); fputc('\n', catalog_f); 
        fputs(publisher[i], catalog_f); fputc('\n', catalog_f); 
        fputc('\n', catalog_f);
    }
}

int readCatFile() {
    int lines = 0;
    // Count lines
    while (EOF != (fscanf(catalog_f, "%*[^\n]"), fscanf(catalog_f, "%*c"))) {
        lines++;
    }
    // And reset
    rewind(catalog_f);

    if(lines % 4) {
        return 1;
    }

    int books = lines / 4;
    for(int i = 0; i < books; i++) {
        fgets(name[i], MAX_BUF, catalog_f);
        fgets(author[i], MAX_BUF, catalog_f);
        fgets(publisher[i], MAX_BUF, catalog_f);
        fscanf(catalog_f, "%*c"); // Swallow the empty line
    }
    numBooks = books;
}

void mEnter() {

    int nlen, alen, plen;
    
    printf("Enter blank name to end.\n");
    while(true) {
        printf("Name: ");
        fgets(name[numBooks], MAX_BUF, stdin);

        // If name is blank ("\n\0")
        if(!(name[1])) {
            break;
        }

        printf("Author: ");
        fgets(author[numBooks], MAX_BUF, stdin);

        printf("Publisher: ");
        fgets(publisher[numBooks], MAX_BUF, stdin);
        
        numBooks++;


    }
}

int main(int argc, char *argv[]) {
    if((name = (char**) malloc(MAX_BUF * MAX_BUF * sizeof(char))) == NULL) {
        printf("Unable to allocate memory for 'name[][]'\n");
    } else if((author = (char**) malloc(MAX_BUF * MAX_BUF * sizeof(char))) == NULL) {
        printf("Unable to allocate memory for 'author[][]'\n");
    } else if((publisher = (char**) malloc(MAX_BUF * MAX_BUF * sizeof(char))) == NULL) {
        printf("Unable to allocate memory for 'publisher[][]'\n");
    } else {
        printf("Allocation rules!\n");
    }

    if((catalog_f = fopen("CATALOG.txt", "rw")) == NULL) {
        printf("Unable to open CATALOG.txt file");
    } else { printf("Read file"); }

    if(!readCatFile()) {
        printf("Unable to read catalog file into memory!\n");
    }

    while(true) {
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
                exit(0);
                break;

            case 5:
                if(writeCatFile()) {
                    printf("Wrote to Catalog file.\n");
                } else {
                    printf("Failed to write to Catalog file!\n");
                }

                break;
        }
    }
}
