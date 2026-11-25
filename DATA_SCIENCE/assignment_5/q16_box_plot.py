from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"
OUTPUT_DIR = BASE_DIR / "outputs"

df = pd.read_csv(DATA_FILE)
subject_columns = ["Python_Marks", "AI_Marks", "Network_Marks"]
OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

plt.figure(figsize=(8, 5))
plt.boxplot(
    [df[column] for column in subject_columns],
    tick_labels=subject_columns,
    patch_artist=True,
)
plt.title("Comparison of Subject Marks")
plt.xlabel("Subject")
plt.ylabel("Marks")
plt.grid(axis="y", linestyle="--", alpha=0.5)
plt.tight_layout()
plt.savefig(OUTPUT_DIR / "q16_subject_marks_boxplot.png")
plt.show()
