from pathlib import Path
import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"

df = pd.read_csv(DATA_FILE)
subject_columns = ["Python_Marks", "AI_Marks", "Network_Marks"]
df["Average_Marks"] = df[subject_columns].mean(axis=1)

df["Performance_Level"] = df["Average_Marks"].apply(
    lambda average: "Excellent" if average >= 85
    else ("Good" if average >= 70 else "Needs Improvement")
)
df = df.drop(columns=["Age"])

print("\nDataFrame after adding Performance_Level and deleting Age:")
print(df)
