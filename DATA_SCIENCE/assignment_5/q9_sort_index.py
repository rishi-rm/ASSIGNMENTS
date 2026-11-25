from pathlib import Path
import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"

df = pd.read_csv(DATA_FILE)
df = df.set_index("Student_ID")
df_descending = df.sort_index(ascending=False)
print("\nDataFrame sorted by Student_ID index in descending order:")
print(df_descending)

df_reset = df_descending.reset_index()
print("\nDataFrame after resetting the index:")
print(df_reset)
