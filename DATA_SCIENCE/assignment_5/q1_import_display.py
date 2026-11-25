from pathlib import Path
import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"

try:
    df = pd.read_csv(DATA_FILE)
except FileNotFoundError:
    print("Error: student_performance.csv was not found.")
else:
    print("\nComplete DataFrame:")
    print(df)
    print("\nFirst 5 rows:")
    print(df.head())
    print("\nLast 3 rows:")
    print(df.tail(3))
