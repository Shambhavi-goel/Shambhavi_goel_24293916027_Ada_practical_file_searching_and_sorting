import matplotlib.pyplot as plt

# Number of items
x = [3, 4, 5, 6, 7, 8]

# Space complexity values (in terms of memory usage, estimated)
# 0/1 Knapsack uses a 2D DP table of size n*W
# Fractional Knapsack uses an array of structs (1D)
# These numbers are illustrative (in KB or relative units)
zero_one_space = [0.012, 0.016, 0.024, 0.032, 0.040, 0.048]  # increasing with n*W
fractional_space = [0.004, 0.005, 0.006, 0.007, 0.008, 0.009]  # increasing with n

plt.figure(figsize=(8, 5))

# Fractional Knapsack Space
plt.plot(
    x, fractional_space,
    color='red',
    linestyle='-',
    linewidth=2.5,
    marker='o',
    markersize=8,
    markerfacecolor='yellow',
    markeredgecolor='black',
    label="Fractional Knapsack"
)

# 0/1 Knapsack Space
plt.plot(
    x, zero_one_space,
    color='green',
    linestyle='--',
    linewidth=2.5,
    marker='s',
    markersize=8,
    markerfacecolor='lightblue',
    markeredgecolor='black',
    label="0/1 Knapsack"
)

plt.title("Space Complexity of 0/1 and Fractional Knapsack", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("Number of Items (n)", fontsize=12, color='purple')
plt.ylabel("Memory Usage (KB / Relative units)", fontsize=12, color='purple')

plt.grid(True)
plt.legend()
plt.show()
