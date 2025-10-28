import matplotlib.pyplot as plt

x = [10, 20, 30, 40, 50]

# Conceptual Space Complexity values
# Recursive (Naive): O(N) - high stack depth
recursive_space = [15, 25, 35, 45, 55] 
# Iterative: O(1) - constant minimal space
iterative_space = [2, 2, 2, 2, 2] 
# Top-down (Memoization): O(N) - memo table + recursion stack
top_down_space = [12, 22, 32, 42, 52] 
# Bottom-up (Dynamic Programming): O(N) - DP table size (assuming full table)
bottom_up_space = [10, 20, 30, 40, 50] 


plt.figure(figsize=(8, 5))

# Recursive
plt.plot(
    x, recursive_space,
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
    x, iterative_space,
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
    x, top_down_space,
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
    x, bottom_up_space,
    color='brown',
    linestyle=':',
    linewidth=2.5,
    marker='p',
    markersize=8,
    markerfacecolor='pink',
    markeredgecolor='black',
    label="Bottom Up"
)

plt.title("Space Complexity of the four methods of Fibonacci Series", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of terms(n)", fontsize=12, color='purple')
plt.ylabel("Space taken (units)", fontsize=12, color='purple')

plt.grid(True)
plt.legend()
plt.ylim(bottom=0) # Ensure y-axis starts from 0 for better representation
plt.show()