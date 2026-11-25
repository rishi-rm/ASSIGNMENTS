from pathlib import Path
import pandas as pd

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"

df = pd.read_csv(DATA_FILE)
subject_columns = ["Python_Marks", "AI_Marks", "Network_Marks"]
df["Average_Marks"] = df[subject_columns].mean(axis=1)

python_ascending = df.sort_values("Python_Marks", ascending=True)
average_descending = df.sort_values("Average_Marks", ascending=False)
department_python = df.sort_values(["Department", "Python_Marks"], ascending=[True, False])
top_three = average_descending.head(3)

print("\nSorted by Python_Marks (Ascending):")
print(python_ascending)
print("\nSorted by Average_Marks (Descending):")
print(average_descending)
print("\nSorted by Department (Ascending) and Python_Marks (Descending):")
print(department_python)
print("\nTop 3 Students by Average_Marks:")
print(top_three[["Student_ID", "Name", "Department", "Average_Marks"]])
