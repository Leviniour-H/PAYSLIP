#include <stdio.h>
#include "main.h"

void printEmployeeDetails(Employee employee) {
    printf("\nEmployee Details:\n");
    printf("Employee ID: %d\n", employee.employee_id);
    printf("Employee Name: %s\n", employee.employee_name);
    printf("Department: %s\n", employee.department);
    printf("Basic Salary: %.2lf\n", employee.basic_salary);
    printf("Housing Allowance: %.2lf\n", employee.housing_allowance);
    printf("Transport Allowance: %.2lf\n", employee.transport_allowance);
}