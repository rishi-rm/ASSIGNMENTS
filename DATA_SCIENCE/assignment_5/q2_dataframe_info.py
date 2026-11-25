from pathlib import Path
import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"

df = pd.read_csv(DATA_FILE)
print("\nDataFrame Information:")
df.info()
print("\nShape (rows, columns):", df.shape)
print("Size (total values):", df.size)
print("Columns:", df.columns.tolist())
print("\nData types:")
print(df.dtypes)
