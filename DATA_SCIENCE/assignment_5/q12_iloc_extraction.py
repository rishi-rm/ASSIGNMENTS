from pathlib import Path
import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"

df = pd.read_csv(DATA_FILE)

print("\nFirst 5 rows:")
print(df.iloc[:5])
print("\nRows 3 to 7 and columns 2 to 5:")
print(df.iloc[2:7, 1:5])
print("\nLast 4 rows and first 3 columns:")
print(df.iloc[-4:, :3])
print("\nSecond row and Python_Marks column:")
print(df.iloc[1, df.columns.get_loc("Python_Marks")])
