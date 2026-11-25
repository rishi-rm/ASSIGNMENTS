from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"
OUTPUT_DIR = BASE_DIR / "outputs"

df = pd.read_csv(DATA_FILE)
subject_columns = ["Python_Marks", "AI_Marks", "Network_Marks"]
average_marks = df[subject_columns].mean()
OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

plt.figure(figsize=(8, 5))
plt.bar(subject_columns, average_marks, color=["blue", "green", "orange"])
plt.title("Average Marks in Three Subjects")
plt.xlabel("Subject")
plt.ylabel("Average Marks")
plt.grid(axis="y", linestyle="--", alpha=0.5)
plt.tight_layout()
plt.savefig(OUTPUT_DIR / "q14_average_subject_bar.png")
plt.show()
print("\nAverage Subject Marks:")
print(average_marks)
