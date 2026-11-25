import csv
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent
INPUT_FILE = BASE_DIR / "data" / "students.csv"
OUTPUT_FILE = BASE_DIR / "outputs" / "q1_student_analysis.csv"
SUBJECTS = ["Python", "DBMS", "Maths"]
PASS_MARK = 40


def read_students(path):
    with path.open("r", newline="", encoding="utf-8") as file:
        return list(csv.DictReader(file))


def main():
    students = read_students(INPUT_FILE)
    if not students:
        print("No student records found.")
        return

    print("\nAll Student Records")
    print("-" * 60)
    for student in students:
        print(student)

    subject_mark_lists = {subject: [] for subject in SUBJECTS}
    for student in students:
        marks = [float(student[subject]) for subject in SUBJECTS]
        student["Average"] = round(sum(marks) / len(marks), 2)
        student["Result"] = "Pass" if all(mark >= PASS_MARK for mark in marks) else "Fail"
        for subject, mark in zip(SUBJECTS, marks):
            subject_mark_lists[subject].append(mark)

    highest = max(students, key=lambda row: row["Average"])
    print("\nHighest Average:", highest["Name"], "-", highest["Average"])
    print("\nSubject Highest and Lowest Marks:")
    for subject, marks in subject_mark_lists.items():
        print(f"{subject}: Highest={max(marks)}, Lowest={min(marks)}")

    low_attendance = [row["Name"] for row in students if float(row["Attendance"]) < 75]
    print("\nAttendance below 75%:", ", ".join(low_attendance) if low_attendance else "None")
    passed = sum(row["Result"] == "Pass" for row in students)
    failed = len(students) - passed
    print(f"Passed: {passed}")
    print(f"Failed: {failed}")

    OUTPUT_FILE.parent.mkdir(parents=True, exist_ok=True)
    fieldnames = list(students[0].keys())
    with OUTPUT_FILE.open("w", newline="", encoding="utf-8") as file:
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(students)
    print("\nFinal analysis saved to:", OUTPUT_FILE)


if __name__ == "__main__":
    main()
