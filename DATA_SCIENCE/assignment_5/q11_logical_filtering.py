from pathlib import Path
import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"

df = pd.read_csv(DATA_FILE)
subject_columns = ["Python_Marks", "AI_Marks", "Network_Marks"]
df["Average_Marks"] = df[subject_columns].mean(axis=1)

python_ai = df[(df["Python_Marks"] > 75) & (df["AI_Marks"] > 80)]
attendance_or_study = df[(df["Attendance"] > 90) | (df["Study_Hours"] > 5)]
cse_above_75 = df[(df["Department"] == "CSE") & (df["Average_Marks"] > 75)]
not_it = df[~(df["Department"] == "IT")]

print("\nPython > 75 AND AI > 80:")
print(python_ai)
print("\nAttendance > 90 OR Study_Hours > 5:")
print(attendance_or_study)
print("\nCSE students with Average_Marks > 75:")
print(cse_above_75)
print("\nStudents who do not belong to IT:")
print(not_it)
