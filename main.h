// main.h

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

typedef struct {
    int employee_id;
    char employee_name[50];
    char department[50];
    double basic_salary;
    double housing_allowance;
    double transport_allowance;
    // Add other relevant fields here later
} Employee;

Employee getEmployeeData();
double calculateGrossSalary(Employee employee);
double calculatePAYE(double grossSalary);
void calculateOtherDeductions(double grossSalary, double *socialHealth, double *housingLevy, double *nssf);
double calculateNetSalary(double grossSalary, double paye, double socialHealth, double housingLevy, double nssf);
void writePayslipCSV(Employee employee, double grossSalary, double paye, double socialHealth, double housingLevy, double nssf, double netSalary, const char *filename);

#endif // MAIN_H