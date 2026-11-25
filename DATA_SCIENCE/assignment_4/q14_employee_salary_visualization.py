import csv
from pathlib import Path
import matplotlib.pyplot as plt

BASE_DIR = Path(__file__).resolve().parent
INPUT_FILE = BASE_DIR / "data" / "employee_salaries.csv"
OUTPUT_DIR = BASE_DIR / "outputs"


def main():
    with INPUT_FILE.open("r", newline="", encoding="utf-8") as file:
        employees = list(csv.DictReader(file))
    if not employees:
        print("No employee records found.")
        return

    names = [row["Name"] for row in employees]
    salaries = [float(row["Salary"]) for row in employees]
    department_counts = {}
    for employee in employees:
        department = employee["Department"]
        department_counts[department] = department_counts.get(department, 0) + 1

    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

    plt.figure(figsize=(12, 6))
    plt.bar(names, salaries, color="teal")
    plt.xticks(rotation=45, ha="right")
    plt.title("Employee Salaries")
    plt.xlabel("Employee")
    plt.ylabel("Salary (Rs.)")
    plt.grid(axis="y", linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q14_employee_salary_bar.png")
    plt.show()

    plt.figure(figsize=(8, 5))
    plt.hist(salaries, bins=8, color="orchid", edgecolor="black")
    plt.title("Salary Distribution")
    plt.xlabel("Salary (Rs.)")
    plt.ylabel("Number of Employees")
    plt.grid(axis="y", linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q14_salary_histogram.png")
    plt.show()

    plt.figure(figsize=(7, 7))
    plt.pie(
        department_counts.values(),
        labels=department_counts.keys(),
        autopct="%1.1f%%",
        startangle=90,
    )
    plt.title("Department-Wise Employee Distribution")
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q14_department_pie.png")
    plt.show()

    plt.figure(figsize=(8, 5))
    plt.boxplot(salaries, orientation="vertical", patch_artist=True)
    plt.title("Salary Box Plot")
    plt.ylabel("Salary (Rs.)")
    plt.grid(axis="y", linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q14_salary_boxplot.png")
    plt.show()
    print("\nCharts saved in:", OUTPUT_DIR)


if __name__ == "__main__":
    main()
