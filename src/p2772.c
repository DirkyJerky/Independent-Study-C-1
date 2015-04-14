#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 512

int main(int argc, char *argv[]) {
    struct emp {
        char name[64];
        long int telephone;
        int hoursWorked;
        float hourlyWage;
    };

    struct emp employees[10];

    FILE *emp_f;

    if((emp_f = fopen("EMP.bin", "r")) == NULL) {
        printf("Unable to open employee file!\n");
        exit(1);
    }

    if (fread(&employees, sizeof(struct emp), 10, emp_f) == 0) {
        printf("Unable to read from employee file!\n");
        exit(1);
    }

    for(int i = 0; i < 10; i++) {
        printf("Employee #%d:\n", i + 1);

        printf("Name: %s\n", employees[i].name);

        printf("Telephone number: %ld\n", employees[i].telephone);

        printf("Hours Worked: %d\n", employees[i].hoursWorked);

        printf("Hourly Wage: %.2f\n", employees[i].hourlyWage);
        printf("\n");


    }
}
