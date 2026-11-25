def q1():
    roll = int(input("Enter roll number: "))
    name = input("Enter name: ")
    cgpa = float(input("Enter CGPA: "))
    print((roll, name, cgpa))


def q2():
    values = tuple(map(int, input("Enter 6 integers separated by spaces: ").split()))
    print(values[::-1])


def q3():
    t = (10, 20, 30, 40, 50, 60)
    print(t[1:-1])


def q4():
    t1 = (1, 2, 3)
    t2 = (4, 5)
    print(t1 + t2)


def q5():
    print((1, 3, 5) * 3)


def q6():
    t = (10, 15, 20, 25, 30)
    value = int(input("Enter value to check: "))
    print(value in t)


def q7():
    t = tuple(map(int, input("Enter tuple values: ").split()))
    value = int(input("Enter value to count: "))
    print(t.count(value))


def q8():
    t = tuple(map(int, input("Enter tuple values: ").split()))
    value = int(input("Enter value to find: "))
    try:
        print(t.index(value))
    except ValueError:
        print("Value not found")


def q9():
    t = tuple(map(int, input("Enter tuple values: ").split()))
    print("Max =", max(t))
    print("Min =", min(t))


def q10():
    t = tuple(map(int, input("Enter tuple values: ").split()))
    print(sum(t))


def q11():
    text = input("Enter a string: ")
    t = tuple(text)
    print(t)


def q12():
    values = [11, 22, 33, 44]
    t = tuple(values)
    print(t)
    print(type(t))


def q13():
    t = tuple(map(int, input("Enter tuple values: ").split()))
    print(sorted(t))


def q14():
    t = tuple(map(int, input("Enter tuple values: ").split()))
    print(len(t))


def q15():
    t = (2, 4, 6, 8, 10)
    print(all(value % 2 == 0 for value in t))


def q16():
    students = {"Aman": 78, "Riya": 85, "Kabir": 69, "Neha": 90, "Arjun": 74}
    print("Keys:", list(students.keys()))
    print("Values:", list(students.values()))


def q17():
    students = {"Aman": 78, "Riya": 85, "Kabir": 69, "Neha": 90, "Arjun": 74}
    name = input("Enter name: ")
    if name in students:
        print("Key found. Value =", students[name])
    else:
        print("Key not found")


def q18():
    d1 = {1: "A", 2: "B"}
    d2 = {3: "C", 4: "D"}
    merged = d1.copy()
    merged.update(d2)
    print("Merged Dictionary:", merged)


def q19():
    fruits = {"Apple": 100, "Banana": 40, "Mango": 60}
    fruit = input("Enter fruit: ")
    price = int(input("Enter new price: "))
    if fruit in fruits:
        fruits[fruit] = price
    else:
        print("Fruit not found")
    print("Updated Dictionary:", fruits)


def q20():
    fruits = {"Apple": 120, "Banana": 40, "Mango": 60}
    key = input("Enter key to delete: ")
    fruits.pop(key, None)
    print("Updated Dictionary:", fruits)


def q21():
    d = {"Apple": 120, "Banana": 40, "Mango": 60}
    print("Total keys =", len(d))


def q22():
    students = {101: "Amit", 102: "Neha", 103: "Rahul"}
    for student_id, name in students.items():
        print(student_id, "->", name)


def q23():
    subjects = {"Maths": 95, "Science": 88, "English": 82}
    subject = max(subjects, key=subjects.get)
    print(f"Highest Marks Subject: {subject} = {subjects[subject]}")


def q24():
    keys = [1, 2, 3]
    values = ["A", "B", "C"]
    print(dict(zip(keys, values)))


def q25():
    original = {1: 10, 2: 20}
    copied = original.copy()
    print("Original:", original)
    print("Copied:", copied)


def q26():
    d = {"A": 70, "B": 90, "C": 60}
    value = int(input("Enter value: "))
    if value in d.values():
        print("Value exists")
    else:
        print("Value does not exist")


def q27():
    d = {1: 10, 2: 20, 3: 30}
    d.popitem()
    print("Updated Dictionary after removing last item:", d)


def q28():
    inventory = {"Pen": 10, "Pencil": 20}
    item = input("Enter item: ")
    if item in inventory:
        inventory[item] += 5
    else:
        print("Item not found")
    print("Updated Dictionary:", inventory)


def q29():
    inventory = {"Pen": 15, "Pencil": 20}
    for item, quantity in inventory.items():
        print(f"{item}: {quantity}")


def q30():
    d = {"A": 10, "B": 20, "C": 30}
    d.clear()
    print("Dictionary after clear:", d)


def q31():
    squares = {number: number ** 2 for number in range(1, 6)}
    print(squares)


def q32():
    ages = {"Aman": 20, "Neha": 21, "Riya": 19}
    name = input("Enter name: ")
    if name in ages:
        print("Age =", ages[name])
    else:
        print("Name not found")


def q33():
    d = {}
    for _ in range(3):
        key = input("Enter key: ")
        value = input("Enter value: ")
        d[key] = value
    print(d)


def q34():
    capitals = {"India": "Delhi", "Japan": "Tokyo", "France": "Paris"}
    for capital in capitals.values():
        print(capital)


def q35():
    values = {"A": 40, "B": 75, "C": 60, "D": 20}
    count = sum(value > 50 for value in values.values())
    print("Count =", count)


def q36():
    numbers = set(map(int, input("Enter numbers separated by spaces: ").split()))
    print(numbers)


def q37():
    values = {10, 3.5, "Python"}
    print("Set:", values)
    print("Length:", len(values))


def q38():
    cities = ["Delhi", "Mumbai", "Delhi", "Chennai", "Mumbai", "Pune"]
    print(set(cities))


def q39():
    values = set()
    for _ in range(3):
        values.add(input("Enter an element: "))
    print(values)


def q40():
    values = {2, 4, 6}
    number = int(input("Enter a number to add: "))
    values.add(number)
    print(values)


def q41():
    values = {1, 2, 3}
    numbers = (4, 5, 6)
    values.update(numbers)
    print(values)


def q42():
    values = {"a", "b"}
    text = input("Enter a string: ")
    values.update(text)
    print(values)


def q43():
    first = {1, 2, 3}
    second = {3, 4, 5}
    first.update(second)
    print(first)


def q44():
    values = {10, 20, 30, 40}
    element = int(input("Enter element to discard: "))
    values.discard(element)
    print(values)


def q45():
    values = set(map(int, input("Enter numbers separated by spaces: ").split()))
    values = {number for number in values if number >= 10}
    print(values)


def q46():
    languages = {"Python", "Java", "C", "C++", "JavaScript"}
    word = input("Enter a programming language: ")
    if word in languages:
        print("Language exists")
    else:
        print("Language does not exist")


def q47():
    values = set(map(int, input("Enter numbers separated by spaces: ").split()))
    values = {number for number in values if number % 3 != 0}
    print(values)


def q48():
    a = set(map(int, input("Enter elements of set A: ").split()))
    b = set(map(int, input("Enter elements of set B: ").split()))
    print("Union:", a | b)
    print("Intersection:", a & b)
    print("Difference (A - B):", a - b)
    print("Symmetric Difference:", a ^ b)


def q49():
    math_students = set(input("Enter Math students separated by spaces: ").split())
    physics_students = set(input("Enter Physics students separated by spaces: ").split())
    print("Students enrolled in both:", math_students & physics_students)


def q50():
    course1 = set(input("Enter first course roll numbers: ").split())
    course2 = set(input("Enter second course roll numbers: ").split())
    print("Students in exactly one course:", course1 ^ course2)


def q51():
    a = set(map(int, input("Enter elements of set A: ").split()))
    b = set(map(int, input("Enter elements of set B: ").split()))
    print("No common elements:", a.isdisjoint(b))


def q52():
    a = set(map(int, input("Enter elements of set A: ").split()))
    b = set(map(int, input("Enter elements of set B: ").split()))
    print("A is subset of B:", a.issubset(b))
    print("A is superset of B:", a.issuperset(b))


def q53():
    sentence = input("Enter a sentence: ")
    unique_characters = set(sentence) - {" "}
    print(unique_characters)