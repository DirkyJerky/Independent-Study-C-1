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

    if((emp_f = fopen("EMP.bin", "w")) == NULL) {
        printf("Unable to open employee file!\n");
        exit(1);
    }

    for(int i = 0; i < 10; i++) {
        printf("Employee #%d:\n", i + 1);

        printf("Name: ");
        scanf("%63s", &(employees[i].name));

        printf("Telephone number: ");
        scanf("%ld", &(employees[i].telephone));

        printf("Hours Worked: ");
        scanf("%d", &(employees[i].hoursWorked));

        printf("Hourly Wage: ");
        scanf("%f", &(employees[i].hourlyWage));


    }
    if (fwrite(&employees, sizeof(struct emp), 10, emp_f) == 0) {
        printf("Unable to write to employee file!\n");
        exit(1);
    }
}
