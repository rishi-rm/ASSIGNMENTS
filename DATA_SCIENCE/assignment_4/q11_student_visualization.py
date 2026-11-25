import csv
from pathlib import Path
import matplotlib.pyplot as plt

BASE_DIR = Path(__file__).resolve().parent
INPUT_FILE = BASE_DIR / "data" / "students.csv"
OUTPUT_DIR = BASE_DIR / "outputs"


def main():
    with INPUT_FILE.open("r", newline="", encoding="utf-8") as file:
        students = list(csv.DictReader(file))
    if not students:
        print("No student records found.")
        return

    names = [row["Name"] for row in students]
    averages = [
        (float(row["Python"]) + float(row["DBMS"]) + float(row["Maths"])) / 3
        for row in students
    ]
    subjects = ["Python", "DBMS", "Maths"]
    marks_by_subject = [
        [float(row[subject]) for row in students]
        for subject in subjects
    ]
    totals = [sum(values) for values in zip(*marks_by_subject)]

    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)

    plt.figure(figsize=(11, 6))
    plt.bar(names, averages, color="skyblue")
    plt.xticks(rotation=45, ha="right")
    plt.title("Average Marks of Students")
    plt.xlabel("Student")
    plt.ylabel("Average Marks")
    plt.grid(axis="y", linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q11_student_average_bar.png")
    plt.show()

    plt.figure(figsize=(11, 6))
    for subject, marks in zip(subjects, marks_by_subject):
        plt.plot(names, marks, marker="o", label=subject)
    plt.xticks(rotation=45, ha="right")
    plt.title("Student Marks in Different Subjects")
    plt.xlabel("Student")
    plt.ylabel("Marks")
    plt.legend()
    plt.grid(True, linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q11_subject_marks_line.png")
    plt.show()

    plt.figure(figsize=(8, 5))
    plt.hist(totals, bins=6, color="orange", edgecolor="black")
    plt.title("Distribution of Student Total Marks")
    plt.xlabel("Total Marks")
    plt.ylabel("Number of Students")
    plt.grid(axis="y", linestyle="--", alpha=0.5)
    plt.tight_layout()
    plt.savefig(OUTPUT_DIR / "q11_total_marks_histogram.png")
    plt.show()
    print("\nCharts saved in:", OUTPUT_DIR)


if __name__ == "__main__":
    main()
