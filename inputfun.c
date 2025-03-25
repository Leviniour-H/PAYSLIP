#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"



Employee getEmployeeData() {
    Employee emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.employee_id);
    getchar(); // Consume newline left by scanf

    printf("Enter Employee Name: ");
    fgets(emp.employee_name, sizeof(emp.employee_name), stdin);
    emp.employee_name[strcspn(emp.employee_name, "\n")] = 0; // Remove trailing newline

    printf("Enter Department: ");
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = 0;

    printf("Enter Basic Salary: ");
    scanf("%lf", &emp.basic_salary);

    printf("Enter Housing Allowance: ");
    scanf("%lf", &emp.housing_allowance);

    printf("Enter Transport Allowance: ");
    scanf("%lf", &emp.transport_allowance);

    return emp;
}

