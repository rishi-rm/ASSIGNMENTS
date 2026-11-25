from scipy.stats import binom

n = 6
p = 0.8

# P(X >= 5) = 1 - P(X <= 4)
probability = 1 - binom.cdf(4, n, p)

print("Probability that at least 5 students pass:")
print(probability)
