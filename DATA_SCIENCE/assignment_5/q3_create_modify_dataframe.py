from pathlib import Path
import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"

df = pd.read_csv(DATA_FILE)
subject_columns = ["Python_Marks", "AI_Marks", "Network_Marks"]
df["Total_Marks"] = df[subject_columns].sum(axis=1)
df["Average_Marks"] = df[subject_columns].mean(axis=1)
df["Result"] = df["Average_Marks"].apply(
    lambda average: "Pass" if average >= 40 else "Fail"
)
print("\nUpdated DataFrame:")
print(df)
