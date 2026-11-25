from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"
OUTPUT_DIR = BASE_DIR / "outputs"

df = pd.read_csv(DATA_FILE)
department_counts = df["Department"].value_counts()
OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

print("\nDepartment-wise student distribution:")
print(department_counts)

plt.figure(figsize=(7, 7))
plt.pie(
    department_counts.values,
    labels=department_counts.index,
    autopct="%1.1f%%",
    startangle=90,
)
plt.title("Department-wise Student Distribution")
plt.tight_layout()
plt.savefig(OUTPUT_DIR / "q17_department_pie.png")
plt.show()
