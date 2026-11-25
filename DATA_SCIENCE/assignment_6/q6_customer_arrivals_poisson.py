from scipy.stats import poisson

mean = 4
x = 2

# PMF gives the probability of exactly x arrivals.
probability = poisson.pmf(x, mean)
percentage = probability * 100

print("Probability of exactly 2 customers:")
print(probability)
print("Percentage:")
print(f"{percentage}%")
