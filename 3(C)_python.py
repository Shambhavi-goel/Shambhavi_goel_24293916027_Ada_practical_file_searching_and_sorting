import matplotlib.pyplot as plt

x = [2,4,8,16,32,64]
y = [0.000012,0.000192, 0.001019, 0.006385, 0.041117, 0.329413]

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

plt.title("Time Complexity of Matrix Multiplication By Strassen's Method", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("Size of the square matrices(n)", fontsize=12, color='purple')
plt.ylabel("Time taken(seconds)", fontsize=12, color='purple')

plt.grid(True)
plt.show()
