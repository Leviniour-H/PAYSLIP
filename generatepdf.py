import csv
from reportlab.lib.pagesizes import letter
from reportlab.pdfgen import canvas
from reportlab.lib.units import inch
import os

def read_employee_csv(filename):
    """Reads all employee data from a CSV file."""
    employee_data_list = []
    with open(filename, mode='r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            employee_data_list.append(row)
    return employee_data_list

def generate_employee_payslip_pdf(employee_data, output_filename, logo_filename):
    """Generates an employee payslip PDF with spaced employee details."""
    c = canvas.Canvas(output_filename, pagesize=letter)
    width, height = letter

    logo_width = 133
    logo_height = 100
    logo_x = (width - logo_width) / 2
    logo_y = height - logo_height - 40

    c.drawImage(logo_filename, logo_x, logo_y, width=logo_width, height=logo_height)

    # Title
    c.setFont("Helvetica-Bold", 16)
    c.drawString(230, height - 160, "EMPLOYEE PAYSLIP")

    # Employee Details with Spacing
    c.setFont("Helvetica", 12)
    y_position = height - 2.5 * inch  # Start position

    details = [
        ("Employee ID", employee_data.get("Employee ID", "N/A")),
        ("Employee Name", employee_data.get("Employee Name", "N/A")),
        ("Department", employee_data.get("Department", "N/A")),
        ("Gross Salary", employee_data.get("Gross Salary", "N/A")),
        ("PAYE", employee_data.get("PAYE", "N/A")),
        ("Social Health", employee_data.get("Social Health", "N/A")),
        ("Housing Levy", employee_data.get("Housing Levy", "N/A")),
        ("NSSF", employee_data.get("NSSF", "N/A")),
        ("Net Salary", employee_data.get("Net Salary", "N/A")),
    ]

    for label, value in details:
        c.drawString(inch, y_position, f"{label}: {value}")
        y_position -= 0.4 * inch  # Adjust this value for spacing

    c.save()

def main():
    csv_filename = 'payslips.csv'
    logo_filename = 'logo.jpeg'

    employee_data_list = read_employee_csv(csv_filename)
    for employee_data in employee_data_list:
        employee_id = employee_data.get("Employee ID", "Unknown")
        pdf_filename = f'employee_payslip_{employee_id}.pdf'
        generate_employee_payslip_pdf(employee_data, pdf_filename, logo_filename)
        print(f"Employee payslip generated: {pdf_filename}")

if __name__ == "__main__":
    main()