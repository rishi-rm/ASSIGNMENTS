from scipy.stats import poisson

mean = 3
maximum_errors = 2

# CDF gives the probability of maximum_errors or fewer events.
probability = poisson.cdf(maximum_errors, mean)
percentage = probability * 100

print("Probability of at most 2 errors:")
print(probability)
print("Percentage:")
print(f"{percentage}%")
