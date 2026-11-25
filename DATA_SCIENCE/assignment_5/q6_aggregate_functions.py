from pathlib import Path
import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"

df = pd.read_csv(DATA_FILE)
subject_columns = ["Python_Marks", "AI_Marks", "Network_Marks"]
aggregate = df[subject_columns].agg(["min", "max", "mean", "std"])
print("\nAggregate Subject Statistics:")
print(aggregate)
