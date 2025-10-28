import matplotlib.pyplot as plt

x = [3,4,5,6,7,8]
fractional = [0.000001, 0.000015, 0.000029, 0.000031, 0.000031, 0.000036]
zero_one = [0.000011, 0.000025, 0.000061, 0.000081, 0.000082, 0.000125]


plt.figure(figsize=(8, 5))

# Fractional
plt.plot(
    x, fractional,
    color='red',
    linestyle='-',
    linewidth=2.5,
    marker='o',
    markersize=8,
    markerfacecolor='yellow',
    markeredgecolor='black',
    label="fractional"
)

# 0/1
plt.plot(
    x, zero_one,
    color='green',
    linestyle='--',
    linewidth=2.5,
    marker='s',
    markersize=8,
    markerfacecolor='lightblue',
    markeredgecolor='black',
    label="0/1"
)


plt.title("Time Complexity of the two methods of Knapsack Problem", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of Items(n)", fontsize=12, color='purple')
plt.ylabel("Time taken (seconds)", fontsize=12, color='purple')

plt.grid(True)
plt.legend()
plt.show()
