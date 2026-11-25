from pathlib import Path
import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"

df = pd.read_csv(DATA_FILE)
subject_columns = ["Python_Marks", "AI_Marks", "Network_Marks"]

statistics = pd.DataFrame({
    "Sum": df[subject_columns].sum(),
    "Mean": df[subject_columns].mean(),
    "Minimum": df[subject_columns].min(),
    "Maximum": df[subject_columns].max(),
    "Median": df[subject_columns].median(),
})
print("\nStatistical Analysis:")
print(statistics)
