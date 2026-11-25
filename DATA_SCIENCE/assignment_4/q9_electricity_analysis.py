from pathlib import Path
import numpy as np

BASE_DIR = Path(__file__).resolve().parent
INPUT_FILE = BASE_DIR / "data" / "electricity_consumption.csv"
MONTHS = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]


def main():
    consumption = np.loadtxt(INPUT_FILE, delimiter=",", skiprows=1, usecols=1)
    if consumption.size == 0:
        print("No electricity consumption data found.")
        return

    annual = consumption.sum()
    monthly_average = consumption.mean()
    highest_index = int(consumption.argmax())
    lowest_index = int(consumption.argmin())
    above_average_indices = np.where(consumption > monthly_average)[0]
    monthly_contributions = (consumption / annual) * 100
    sorted_indices = np.argsort(consumption)

    print("\nAnnual consumption:", annual, "kWh")
    print("Monthly average:", round(monthly_average, 2), "kWh")
    print("Highest consumption month:", MONTHS[highest_index], "-", consumption[highest_index], "kWh")
    print("Lowest consumption month:", MONTHS[lowest_index], "-", consumption[lowest_index], "kWh")
    print("Months above average:")
    print(", ".join(MONTHS[index] for index in above_average_indices))
    print("Standard deviation:", round(consumption.std(), 2), "kWh")
    print("\nMonthly percentage contribution:")
    for month, contribution in zip(MONTHS, monthly_contributions):
        print(f"{month}: {contribution:.2f}%")
    print("\nMonths sorted by consumption (lowest to highest):")
    for index in sorted_indices:
        print(f"{MONTHS[index]}: {consumption[index]} kWh")


if __name__ == "__main__":
    main()
