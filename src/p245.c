#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_BUF 512
#define CATF "CATALOG.txt"

FILE *catalog_f;

char name[MAX_BUF][MAX_BUF];
char author[MAX_BUF][MAX_BUF];
char publisher[MAX_BUF][MAX_BUF];
int numBooks = 0;

void consumeLine() {
    while(getchar() != '\n') {}
}


int menu() {
    printf("\n");
    printf("Card Catalog:\n");
    printf("\n");
    printf("1: Enter\n");
    printf("2: Search by Author\n");
    printf("3: Search by Title\n");
    printf("4: Quit\n");
    printf("5: Save to Disk");
    printf("\n");
    printf(":");

    int code;
    scanf("%d", &code);

    consumeLine();
    printf("\n");
    if (!(1 <= code && code <= 5)) {
        return 0;
    }
    return code;
}

int writeCatFile() {
    if ((catalog_f = fopen(CATF, "w")) == NULL) {
        return 1;
    }
    for(int i = 0; i < numBooks; i++) {
        fputs(name[i], catalog_f); // fputc('\n', catalog_f); 
        fputs(author[i], catalog_f); // fputc('\n', catalog_f); 
        fputs(publisher[i], catalog_f); // fputc('\n', catalog_f); 
        fputc('\n', catalog_f);
    }

    fclose(catalog_f);

    return 0;
}

int readCatFile() {
    if(access(CATF, F_OK) != 0) {
        printf("Unable to access Catalog file.\n");
        return 1;
    } else {
        if ((catalog_f = fopen(CATF, "r")) == NULL) {
            return 1;
        }
    } 


    int lines = 0;
    // Count lines
    while (EOF != (fscanf(catalog_f, "%*[^\n]"), fscanf(catalog_f, "%*c"))) {
        lines++;
    }
    // And reset
    rewind(catalog_f);

    if(lines % 4) {
        printf("Malformed Catalog file? (%d lines)", lines);
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
    
    printf("Read %d books into memory.\n", numBooks);

    fclose(catalog_f);

    return 0;
}

void mEnter() {

    int nlen, alen, plen;
    
    printf("Enter blank name to end.\n");
    while(true) {
        printf("Name: ");
        fgets(name[numBooks], MAX_BUF, stdin);

        // If name is blank ("\n\0")
        if(!(name[numBooks][1])) {
            break;
        }

        printf("Author: ");
        fgets(author[numBooks], MAX_BUF, stdin);

        printf("Publisher: ");
        fgets(publisher[numBooks], MAX_BUF, stdin);
        
        numBooks++;


    }
}

void menuLogic() {
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
                return;

            case 5:
                if(writeCatFile() == 0) {
                    printf("Wrote to Catalog file.\n");
                } else {
                    printf("Failed to write to Catalog file!\n");
                }

                break;
        }
    }
}

int main(int argc, char *argv[]) {
//    if((name = (char**) malloc(MAX_BUF * MAX_BUF * sizeof(char))) == NULL) {
//        printf("Unable to allocate memory for 'name[][]'\n");
//    } else if((author = (char**) malloc(MAX_BUF * MAX_BUF * sizeof(char))) == NULL) {
//        printf("Unable to allocate memory for 'author[][]'\n");
//    } else if((publisher = (char**) malloc(MAX_BUF * MAX_BUF * sizeof(char))) == NULL) {
//        printf("Unable to allocate memory for 'publisher[][]'\n");
//    } else {
//        printf("Allocation rules!\n");
//    }

    if(readCatFile() != 0) {
        printf("Unable to read catalog file into memory!\n");
    }

    menuLogic();

    if (catalog_f != NULL) {
        fclose(catalog_f);
    }
}
