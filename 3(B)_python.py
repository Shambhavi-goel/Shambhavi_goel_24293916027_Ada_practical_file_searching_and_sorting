import matplotlib.pyplot as plt

x = [2,4,8,16,32,64]
y = [0.000002,0.000094, 0.000377, 0.002289, 0.013910, 0.135239]

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

plt.title("Time Complexity of Matrix Multiplication By Divide and Conquer Approach", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("Size of the square matrices(n)", fontsize=12, color='purple')
plt.ylabel("Time taken(seconds)", fontsize=12, color='purple')

plt.grid(True)
plt.show()
