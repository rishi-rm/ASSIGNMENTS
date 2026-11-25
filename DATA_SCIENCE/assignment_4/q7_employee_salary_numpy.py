from pathlib import Path
import numpy as np

BASE_DIR = Path(__file__).resolve().parent
INPUT_FILE = BASE_DIR / "data" / "employee_salaries.csv"


def main():
    salaries = np.loadtxt(INPUT_FILE, delimiter=",", skiprows=1, usecols=3)
    if salaries.size == 0:
        print("No salary records found.")
        return

    average = salaries.mean()
    above_average = salaries[salaries > average]
    range_salaries = salaries[(salaries >= 40000) & (salaries <= 80000)]
    percentage_above_60k = (np.sum(salaries > 60000) / salaries.size) * 100

    print("\nSalary Statistics")
    print("Mean:", round(average, 2))
    print("Median:", np.median(salaries))
    print("Maximum:", salaries.max())
    print("Minimum:", salaries.min())
    print("Standard deviation:", round(salaries.std(), 2))
    print("Employees earning above average:", above_average.tolist())
    print("Employees earning between Rs.40,000 and Rs.80,000:", range_salaries.tolist())
    print("Percentage earning above Rs.60,000:", f"{percentage_above_60k:.2f}%")


if __name__ == "__main__":
    main()
