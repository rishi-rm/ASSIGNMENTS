import csv
from pathlib import Path
import numpy as np

BASE_DIR = Path(__file__).resolve().parent
INPUT_FILE = BASE_DIR / "data" / "student_marks_numpy.csv"
SUBJECTS = ["Python", "DBMS", "Maths", "Statistics", "AI"]


def main():
    marks = np.loadtxt(INPUT_FILE, delimiter=",", skiprows=1)
    if marks.size == 0:
        print("No student marks found.")
        return

    subject_averages = marks.mean(axis=0)
    student_averages = marks.mean(axis=1)
    overall_average = marks.mean()
    subject_std = marks.std(axis=0)

    print("\nSubject-wise averages:")
    for subject, average in zip(SUBJECTS, subject_averages):
        print(f"{subject}: {average:.2f}")
    print("\nStudent-wise averages:")
    for index, average in enumerate(student_averages, start=1):
        print(f"Student {index}: {average:.2f}")
    print("\nHighest mark:", marks.max())
    print("Lowest mark:", marks.min())
    print("Overall average:", round(overall_average, 2))
    print("\nStudents scoring above overall average:")
    above_average = np.where(student_averages > overall_average)[0]
    print(", ".join(str(index + 1) for index in above_average) if above_average.size else "None")
    print("\nStandard deviation by subject:")
    for subject, standard_deviation in zip(SUBJECTS, subject_std):
        print(f"{subject}: {standard_deviation:.2f}")

    ranked_indices = np.argsort(student_averages)[::-1]
    print("\nStudents sorted by average (highest first):")
    for index in ranked_indices:
        print(f"Student {index + 1}: {student_averages[index]:.2f}")
    print("\nTop 3 students:", ", ".join(str(index + 1) for index in ranked_indices[:3]))


if __name__ == "__main__":
    main()
