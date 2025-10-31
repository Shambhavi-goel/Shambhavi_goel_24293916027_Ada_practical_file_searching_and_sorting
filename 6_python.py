import matplotlib.pyplot as plt

x = [3,4,5,6,7,8,9,10]
y = [0.002000, 0.006000, 0.003000, 0.003000, 0.002000, 0.004000, 0.002000, 0.006000]


plt.figure(figsize=(8, 5))

plt.plot(
    x, y,
    color='red',
    linestyle='-',
    linewidth=2.5,
    marker='o',
    markersize=8,
    markerfacecolor='yellow',
    markeredgecolor='black',
)


plt.title("Time Complexity of Activity Selection Problem", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of Activities(n)", fontsize=12, color='purple')
plt.ylabel("Time taken (seconds)", fontsize=12, color='purple')

plt.grid(True)
plt.show()
