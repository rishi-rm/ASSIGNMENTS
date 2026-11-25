from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"
OUTPUT_DIR = BASE_DIR / "outputs"

df = pd.read_csv(DATA_FILE)
OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

plt.figure(figsize=(8, 5))
plt.plot(df["Student_ID"], df["Python_Marks"], marker="o", color="blue")
plt.title("Python Marks by Student")
plt.xlabel("Student ID")
plt.ylabel("Python Marks")
plt.grid(True, linestyle="--", alpha=0.5)
plt.tight_layout()
plt.savefig(OUTPUT_DIR / "q13_python_marks_line.png")
plt.show()
print("\nChart saved to:", OUTPUT_DIR / "q13_python_marks_line.png")
