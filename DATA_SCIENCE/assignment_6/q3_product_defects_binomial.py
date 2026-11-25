from scipy.stats import binom

n = 5
p = 0.1
x = 2

# PMF gives the probability of exactly x successes.
probability = binom.pmf(x, n, p)

print("Probability of exactly 2 defective products:")
print(probability)
