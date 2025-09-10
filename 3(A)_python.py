import matplotlib.pyplot as plt

x = [3,4,5,6,7,8,9]
y = [0.000009,0.000017, 0.000025, 0.000034, 0.000063, 0.000086, 0.000091]

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

plt.title("Time Complexity of Matrix Multiplication By Iterative Approach", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("Size of the square matrices(n)", fontsize=12, color='purple')
plt.ylabel("Time taken(seconds)", fontsize=12, color='purple')

plt.grid(True)
plt.show()
