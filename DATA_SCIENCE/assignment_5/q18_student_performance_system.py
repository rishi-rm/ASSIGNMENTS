from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt

BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "student_performance.csv"
OUTPUT_DIR = BASE_DIR / "outputs"

def load_data():
    if not DATA_FILE.exists():
        raise FileNotFoundError("student_performance.csv was not found.")
    return pd.read_csv(DATA_FILE)

def main():
    df = load_data()
    print("\nBasic Dataset Information:")
    print("Shape:", df.shape)
    print("Columns:", df.columns.tolist())
    df.info()

    subject_columns = ["Python_Marks", "AI_Marks", "Network_Marks"]
    df["Total_Marks"] = df[subject_columns].sum(axis=1)
    df["Average_Marks"] = df[subject_columns].mean(axis=1)

    highest = df.loc[df["Average_Marks"].idxmax()]
    print("\nStudent with highest Average_Marks:")
    print(highest[["Student_ID", "Name", "Department", "Average_Marks"]])

    department_average = df.groupby("Department")["Average_Marks"].mean()
    print("\nDepartment-wise average marks:")
    print(department_average)

    eligible = df[
        (df["Attendance"] >= 85) & (df["Average_Marks"] >= 75)
    ]
    print("\nStudents with Attendance >= 85 and Average_Marks >= 75:")
    print(eligible)

    sorted_df = df.sort_values("Average_Marks", ascending=False)
    print("\nStudents sorted by Average_Marks:")
    print(sorted_df)

    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    plt.figure(figsize=(8, 5))
    plt.bar(department_average.index, department_average.values, color="teal")
    plt.title("Department-wise Average Marks")
    plt.xlabel("Department")
    plt.ylabel("Average Marks")
    plt.grid(axis="y", linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q18_department_average_bar.png")
    plt.show()

    plt.figure(figsize=(8, 5))
    plt.hist(sorted_df["Average_Marks"], bins=5, color="coral", edgecolor="black")
    plt.title("Distribution of Student Average Marks")
    plt.xlabel("Average Marks")
    plt.ylabel("Number of Students")
    plt.grid(axis="y", linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q18_average_marks_histogram.png")
    plt.show()

    final_df = sorted_df[
        ["Student_ID", "Name", "Department", "Total_Marks", "Average_Marks"]
    ]
    print("\nFinal DataFrame:")
    print(final_df)
    final_df.to_csv(OUTPUT_DIR / "q18_student_analysis.csv", index=False)
    print("\nFinal analysis saved to:", OUTPUT_DIR / "q18_student_analysis.csv")

if __name__ == "__main__":
    try:
        main()
    except FileNotFoundError as error:
        print("Error:", error)
