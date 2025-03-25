#include "main.h"

int main() {
    Employee employee = getEmployeeData();


    double grossSalary = calculateGrossSalary(employee);
    double paye = calculatePAYE(grossSalary);
    double socialHealth, housingLevy, nssf;
    calculateOtherDeductions(grossSalary, &socialHealth, &housingLevy, &nssf);
    double netSalary = calculateNetSalary(grossSalary, paye, socialHealth, housingLevy, nssf);

     const char *filename = "payslips.csv";

    // Write header only if the file is empty or newly created.
    FILE *file_check = fopen(filename, "r");
    if (file_check == NULL) {
        FILE *header_file = fopen(filename, "w");
        fprintf(header_file, "Employee ID,Employee Name,Department,Gross Salary,PAYE,Social Health,Housing Levy,NSSF,Net Salary\n");
        fclose(header_file);
    } else {
        fclose(file_check);
    }
    writePayslipCSV(employee, grossSalary, paye, socialHealth, housingLevy, nssf, netSalary, filename);

    printf("Payslip data written to %s\n", filename);

    return 0;
}