import matplotlib.pyplot as plt
x = [15, 55, 105, 505, 1005, 3005, 5005, 6005, 7005, 8005]
y = [0.000001, 0.000006, 0.000002, 0.000101, 0.000313, 0.000619, 0.000956, 0.001251, 0.001511, 0.001895]
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
plt.title("Time Complexity of Quick Sort", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("No. of elements(n)", fontsize=12, color='purple')
plt.ylabel("Time taken(seconds)", fontsize=12, color='purple')
plt.grid(True)
plt.show()
