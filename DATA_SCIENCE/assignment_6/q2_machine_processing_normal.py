from scipy.stats import norm

mean = 50
std_dev = 5
lower_limit = 45
upper_limit = 55

# P(lower < X < upper) = F(upper) - F(lower)
probability = norm.cdf(upper_limit, mean, std_dev) - norm.cdf(
    lower_limit, mean, std_dev
)
percentage = probability * 100

print("Probability between 45 and 55 seconds:")
print(probability)
print("Percentage:")
print(f"{percentage}%")
