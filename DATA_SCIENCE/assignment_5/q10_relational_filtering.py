from pathlib import Path
import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"

df = pd.read_csv(DATA_FILE)

print("\nPython_Marks greater than 80:")
print(df[df["Python_Marks"] > 80])
print("\nAttendance greater than or equal to 90:")
print(df[df["Attendance"] >= 90])
print("\nAI_Marks less than 70:")
print(df[df["AI_Marks"] < 70])
print("\nNetwork_Marks not equal to 75:")
print(df[df["Network_Marks"] != 75])
