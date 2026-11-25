def q1_voting_eligibility():
    age = int(input("Enter your age: "))
    if age >= 18:
        print("Eligible to Vote")
    else:
        print("Not Eligible to Vote")


def q2_odd_or_even():
    number = int(input("Enter an integer: "))
    if number % 2 == 0:
        print("Even")
    else:
        print("Odd")


def q3_print_numbers_for():
    n = int(input("Enter a positive integer n: "))
    for number in range(1, n + 1):
        print(number)


def q4_print_numbers_while():
    n = int(input("Enter a positive integer n: "))
    number = 1
    while number <= n:
        print(number)
        number += 1


def q5_sum_first_n_natural_numbers():
    n = int(input("Enter a positive integer n: "))
    total = 0
    for number in range(1, n + 1):
        total += number
    print("Sum =", total)


def q6_skip_character_h():
    text = input("Enter a string: ")
    for character in text:
        if character == "h":
            continue
        print(character)


def q7_break_before_3():
    number = 1
    while True:
        if number == 3:
            break
        print(number)
        number += 1


def q8_weekday_match_case():
    day = int(input("Enter a day number (1-7): "))
    match day:
        case 1:
            print("Monday")
        case 2:
            print("Tuesday")
        case 3:
            print("Wednesday")
        case 4:
            print("Thursday")
        case 5:
            print("Friday")
        case 6:
            print("Saturday")
        case 7:
            print("Sunday")
        case _:
            print("Invalid day number")


def q9_grade_calculator():
    marks = float(input("Enter student's marks (0-100): "))
    if marks < 0 or marks > 100:
        print("Invalid marks")
    elif marks >= 90:
        print("Grade A")
    elif marks >= 80:
        print("Grade B")
    elif marks >= 70:
        print("Grade C")
    elif marks >= 60:
        print("Grade D")
    elif marks >= 50:
        print("Grade E")
    else:
        print("Grade F")


def q10_multiplication_table():
    number = int(input("Enter an integer: "))
    for multiplier in range(1, 11):
        print(f"{number} x {multiplier} = {number * multiplier}")


def q11_factorial_while():
    n = int(input("Enter a non-negative integer: "))
    if n < 0:
        print("Please enter a non-negative integer.")
        return

    factorial = 1
    number = 1
    while number <= n:
        factorial *= number
        number += 1
    print(f"{n}! = {factorial}")


def q12_count_digits():
    number = int(input("Enter an integer: "))
    number = abs(number)

    if number == 0:
        digits = 1
    else:
        digits = 0
        while number > 0:
            number //= 10
            digits += 1

    print("Number of digits =", digits)


def q13_reverse_number():
    number = int(input("Enter an integer: "))
    sign = -1 if number < 0 else 1
    number = abs(number)
    reversed_number = 0

    while number > 0:
        digit = number % 10
        reversed_number = reversed_number * 10 + digit
        number //= 10

    print("Reversed number =", sign * reversed_number)


def q14_prime_number_check():
    number = int(input("Enter an integer: "))

    if number <= 1:
        print("Not Prime")
        return

    divisor = 2
    is_prime = True
    while divisor * divisor <= number:
        if number % divisor == 0:
            is_prime = False
            break
        divisor += 1

    if is_prime:
        print("Prime")
    else:
        print("Not Prime")


def q15_search_for_else():
    numbers = list(map(int, input("Enter numbers separated by spaces: ").split()))
    target = int(input("Enter target value: "))

    for index, number in enumerate(numbers):
        if number == target:
            print("Element found at index", index)
            break
    else:
        print("Element not found")


def q16_password_while_else():
    correct_password = "python123"
    attempts = 0

    while attempts < 3:
        password = input("Enter password: ")
        if password == correct_password:
            print("Login Successful")
            break
        attempts += 1
        print("Incorrect password. Attempts used:", attempts)
    else:
        print("Account Locked")


def q17_point_location_match_case():
    x = float(input("Enter x-coordinate: "))
    y = float(input("Enter y-coordinate: "))

    match (x, y):
        case (0, 0):
            print("Origin")
        case (x, 0) if x > 0:
            print("Positive X-axis")
        case (x, 0) if x < 0:
            print("Negative X-axis")
        case (0, y) if y > 0:
            print("Positive Y-axis")
        case (0, y) if y < 0:
            print("Negative Y-axis")
        case (x, y) if x > 0 and y > 0:
            print("First quadrant")
        case (x, y) if x < 0 and y > 0:
            print("Second quadrant")
        case (x, y) if x < 0 and y < 0:
            print("Third quadrant")
        case (x, y) if x > 0 and y < 0:
            print("Fourth quadrant")


def q18_number_triangle():
    n = int(input("Enter number of rows: "))
    for row in range(1, n + 1):
        for number in range(1, row + 1):
            print(number, end="")
        print()


def q19_skip_multiples_of_3():
    n = int(input("Enter a positive integer n: "))
    for number in range(1, n + 1):
        if number % 3 == 0:
            continue
        print(number, end=" ")
    print()


def q20_number_guessing_game():
    secret_number = 7
    attempts = 0

    while attempts < 5:
        guess = int(input("Guess the secret number (1-10): "))
        attempts += 1

        if guess == secret_number:
            print("Correct!")
            break
        elif guess > secret_number:
            print("Too High")
        else:
            print("Too Low")
    else:
        print("All attempts exhausted. The secret number was", secret_number)