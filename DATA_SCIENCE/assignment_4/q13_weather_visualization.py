from pathlib import Path
import matplotlib.pyplot as plt

BASE_DIR = Path(__file__).resolve().parent
OUTPUT_DIR = BASE_DIR / "outputs"
MONTHS = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
TEMPERATURE = [18, 20, 24, 28, 32, 35, 34, 33, 30, 26, 22, 19]
RAINFALL = [12, 18, 24, 30, 48, 110, 145, 132, 96, 42, 20, 15]


def main():
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

    plt.figure(figsize=(10, 5))
    plt.plot(MONTHS, TEMPERATURE, marker="o", color="red", label="Temperature")
    plt.title("Monthly Temperature")
    plt.xlabel("Month")
    plt.ylabel("Temperature (C)")
    plt.legend()
    plt.grid(True, linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q13_temperature_line.png")
    plt.show()

    plt.figure(figsize=(10, 5))
    plt.bar(MONTHS, RAINFALL, color="blue")
    plt.title("Monthly Rainfall")
    plt.xlabel("Month")
    plt.ylabel("Rainfall (mm)")
    plt.grid(axis="y", linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q13_rainfall_bar.png")
    plt.show()

    plt.figure(figsize=(8, 5))
    plt.hist(TEMPERATURE, bins=6, color="gold", edgecolor="black")
    plt.title("Temperature Distribution")
    plt.xlabel("Temperature (C)")
    plt.ylabel("Frequency")
    plt.grid(axis="y", linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q13_temperature_histogram.png")
    plt.show()

    plt.figure(figsize=(8, 5))
    plt.scatter(TEMPERATURE, RAINFALL, color="purple", s=60)
    plt.title("Temperature vs Rainfall")
    plt.xlabel("Temperature (C)")
    plt.ylabel("Rainfall (mm)")
    plt.grid(True, linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q13_temperature_rainfall_scatter.png")
    plt.show()
    print("\nCharts saved in:", OUTPUT_DIR)


if __name__ == "__main__":
    main()
