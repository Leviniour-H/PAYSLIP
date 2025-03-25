#include "main.h"

double calculateGrossSalary(Employee employee) {
    return employee.basic_salary + employee.housing_allowance + employee.transport_allowance;
}

double calculatePAYE(double grossSalary) {
    double paye = 0.0;

    if (grossSalary <= 24000.0) {
        paye = 0.0;
    } else if (grossSalary <= 100000.0) {
        paye = (grossSalary - 24000.0) * 0.15;
    } else if (grossSalary <= 500000.0) {
        paye = (100000.0 - 24000.0) * 0.15 + (grossSalary - 100000.0) * 0.20;
    } else {
        paye = (100000.0 - 24000.0) * 0.15 + (500000.0 - 100000.0) * 0.20 + (grossSalary - 500000.0) * 0.25;
    }

    return paye;
}

void calculateOtherDeductions(double grossSalary, double *socialHealth, double *housingLevy, double *nssf) {
    *socialHealth = 1500.0;
    *housingLevy = grossSalary * 0.0065; // 0.65%
    *nssf = 2000.0;
};

double calculateNetSalary(double grossSalary, double paye, double socialHealth, double housingLevy, double nssf) {
    return grossSalary - paye - socialHealth - housingLevy - nssf;
}