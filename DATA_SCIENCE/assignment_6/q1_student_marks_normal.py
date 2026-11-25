from scipy.stats import norm

mean = 70
std_dev = 10
marks = 80

# CDF gives the probability of a result less than or equal to marks.
probability = norm.cdf(marks, mean, std_dev)
percentage = probability * 100

print("Probability of scoring less than 80:", probability)
print("Percentage:", f"{percentage}%")
