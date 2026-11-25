from scipy.stats import chisquare

observed = [30, 20, 25, 25]
expected = [25, 25, 25, 25]
degrees_of_freedom = len(observed) - 1
critical_value = 7.815

chi_square_statistic, p_value = chisquare(observed, expected)

print("Chi-square statistic:", chi_square_statistic)
print("P-value:", p_value)
print("Degrees of freedom:", degrees_of_freedom)

if chi_square_statistic > critical_value:
    print("Reject the null hypothesis")
else:
    print("Fail to reject the null hypothesis")
