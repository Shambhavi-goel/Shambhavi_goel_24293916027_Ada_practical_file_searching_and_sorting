import matplotlib.pyplot as plt

x = [2, 4, 8, 16, 32, 64]
iterative = [0.000003, 0.000045, 0.000172, 0.000483, 0.003035, 0.020629]
divide_conquer = [0.000008, 0.000079, 0.000237, 0.002451, 0.022235, 0.155899]
strassen = [0.000017, 0.000121, 0.000728, 0.007388, 0.048201, 0.277320]

plt.figure(figsize=(8, 5))

# Iterative
plt.plot(
    x, iterative,
    color='red',
    linestyle='-',
    linewidth=2.5,
    marker='o',
    markersize=8,
    markerfacecolor='yellow',
    markeredgecolor='black',
    label="Iterative"
)

# Divide & Conquer
plt.plot(
    x, divide_conquer,
    color='green',
    linestyle='--',
    linewidth=2.5,
    marker='s',
    markersize=8,
    markerfacecolor='lightblue',
    markeredgecolor='black',
    label="Divide & Conquer"
)

# Strassen
plt.plot(
    x, strassen,
    color='blue',
    linestyle='-.',
    linewidth=2.5,
    marker='^',
    markersize=8,
    markerfacecolor='orange',
    markeredgecolor='black',
    label="Strassen"
)

plt.title("Time Complexity of the three methods of Matrix Multiplication", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("Size of the square matrices (n)", fontsize=12, color='purple')
plt.ylabel("Time taken (seconds)", fontsize=12, color='purple')

plt.grid(True)
plt.legend()
plt.show()
