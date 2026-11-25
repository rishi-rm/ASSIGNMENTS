import csv
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent
INPUT_FILE = BASE_DIR / "data" / "employees.csv"
OUTPUT_FILE = BASE_DIR / "outputs" / "q2_sorted_employee_salaries.csv"


def main():
    with INPUT_FILE.open("r", newline="", encoding="utf-8") as file:
        employees = list(csv.DictReader(file))
    if not employees:
        print("No employee records found.")
        return

    for employee in employees:
        employee["Total_Salary"] = float(employee["Basic_Salary"]) + float(employee["Bonus"])

    highest = max(employees, key=lambda row: row["Total_Salary"])
    print("\nHighest-Paid Employee:", highest["Name"], "-", highest["Total_Salary"])

    department_salaries = {}
    for employee in employees:
        department = employee["Department"]
        department_salaries.setdefault(department, []).append(employee["Total_Salary"])
    print("\nDepartment-Wise Average Salary:")
    for department, salaries in department_salaries.items():
        print(f"{department}: {sum(salaries) / len(salaries):.2f}")

    experienced = [row["Name"] for row in employees if int(row["Experience"]) > 5]
    print("\nEmployees with more than 5 years:", ", ".join(experienced))

    employees.sort(key=lambda row: row["Total_Salary"], reverse=True)
    print("\nEmployees sorted by total salary:")
    for employee in employees:
        print(f"{employee['Name']}: {employee['Total_Salary']:.2f}")

    OUTPUT_FILE.parent.mkdir(parents=True, exist_ok=True)
    with OUTPUT_FILE.open("w", newline="", encoding="utf-8") as file:
        writer = csv.DictWriter(file, fieldnames=list(employees[0].keys()))
        writer.writeheader()
        writer.writerows(employees)
    print("\nSorted salaries saved to:", OUTPUT_FILE)


if __name__ == "__main__":
    main()
