from pathlib import Path
import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"

df = pd.read_csv(DATA_FILE)
df = df.sort_values("Student_ID")
df["Python_Percentage_Change"] = df["Python_Marks"].pct_change() * 100
print("\nPython Marks Percentage Change:")
print(df[["Student_ID", "Python_Marks", "Python_Percentage_Change"]].to_string(index=False))
