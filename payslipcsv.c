#include "main.h";

void writePayslipCSV(Employee employee, double grossSalary, double paye, double socialHealth, double housingLevy, double nssf, double netSalary, const char *filename) {
    FILE *fp = fopen(filename, "a"); // "a" for append mode

    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "%d,%s,%s,%.2lf,%.2lf,%.2lf,%.2lf,%.2lf,%.2lf\n",
            employee.employee_id,
            employee.employee_name,
            employee.department,
            grossSalary,
            paye,
            socialHealth,
            housingLevy,
            nssf,
            netSalary);

    fclose(fp);
};
