from pathlib import Path
import matplotlib.pyplot as plt

BASE_DIR = Path(__file__).resolve().parent
OUTPUT_DIR = BASE_DIR / "outputs"
MONTHS = ["Jan", "Feb", "Mar", "Apr", "May", "Jun"]
SALES = [25000, 32000, 28000, 41000, 39000, 45000]


def main():
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    highest_index = SALES.index(max(SALES))

    plt.figure(figsize=(9, 5))
    plt.plot(MONTHS, SALES, marker="o", color="green")
    plt.title("Monthly Sales Trend")
    plt.xlabel("Month")
    plt.ylabel("Sales")
    plt.grid(True, linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q12_monthly_sales_line.png")
    plt.show()

    colors = ["orange" if index == highest_index else "steelblue" for index in range(len(MONTHS))]
    plt.figure(figsize=(9, 5))
    bars = plt.bar(MONTHS, SALES, color=colors)
    plt.title("Monthly Sales Bar Chart")
    plt.xlabel("Month")
    plt.ylabel("Sales")
    plt.grid(axis="y", linestyle="--", alpha=0.5)
    plt.annotate(
        "Highest",
        xy=(bars[highest_index].get_x() + bars[highest_index].get_width() / 2, max(SALES)),
        xytext=(0, 15),
        textcoords="offset points",
        ha="center",
    )
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q12_monthly_sales_bar.png")
    plt.show()
    print("\nCharts saved in:", OUTPUT_DIR)


if __name__ == "__main__":
    main()
