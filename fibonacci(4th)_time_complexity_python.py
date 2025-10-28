import matplotlib.pyplot as plt

x = [10,20,30,40,50]
recursive = [0.000000, 0.001000, 0.007000, 0.854000, 121.360000]
iterative = [0.002000, 0.004000, 0.006000, 0.005000, 0.009000]
top_down = [0.000000, 0.000049, 0.000064, 0.000063, 0.000075]
bottom_up= [0.000004, 0.000010, 0.000015, 0.000025, 0.000024]

plt.figure(figsize=(8, 5))

# Recursive
plt.plot(
    x, recursive,
    color='red',
    linestyle='-',
    linewidth=2.5,
    marker='o',
    markersize=8,
    markerfacecolor='yellow',
    markeredgecolor='black',
    label="recursive"
)

# Iterative
plt.plot(
    x, iterative,
    color='green',
    linestyle='--',
    linewidth=2.5,
    marker='s',
    markersize=8,
    markerfacecolor='lightblue',
    markeredgecolor='black',
    label="iterative"
)

# Top Down
plt.plot(
    x, top_down,
    color='blue',
    linestyle='-.',
    linewidth=2.5,
    marker='^',
    markersize=8,
    markerfacecolor='orange',
    markeredgecolor='black',
    label="Top down"
)

# Bottom Up
plt.plot(
    x, bottom_up,
    color='brown',
    linestyle=':',
    linewidth=2.5,
    marker='p',
    markersize=8,
    markerfacecolor='pink',
    markeredgecolor='black',
    label="Bottom Up"
)

plt.yscale('log')

plt.title("Time Complexity of the four methods of Fibonacci Series", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of terms(n)", fontsize=12, color='purple')
plt.ylabel("Time taken (seconds)", fontsize=12, color='purple')

plt.grid(True)
plt.legend()
plt.show()
