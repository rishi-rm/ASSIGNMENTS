from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"
OUTPUT_DIR = BASE_DIR / "outputs"

df = pd.read_csv(DATA_FILE)
subject_columns = ["Python_Marks", "AI_Marks", "Network_Marks"]
df["Average_Marks"] = df[subject_columns].mean(axis=1)
OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

plt.figure(figsize=(8, 5))
plt.hist(df["Average_Marks"], bins=5, color="purple", edgecolor="black")
plt.title("Distribution of Average Marks")
plt.xlabel("Average Marks")
plt.ylabel("Number of Students")
plt.grid(axis="y", linestyle="--", alpha=0.5)
plt.tight_layout()
plt.savefig(OUTPUT_DIR / "q15_average_marks_histogram.png")
plt.show()
