
import matplotlib.pyplot as plt 
input_sizes = [4,5,6,7,8,9,10]
output=[18000,38000,68000,110000,166000,238000,328000]
plt.plot(input_sizes,output,marker='o', linestyle='-', color='blue', linewidth=2)
plt.title("Matrix Chain Multiplication", fontsize=14)
plt.xlabel("Input Size", fontsize=12)
plt.ylabel("Steps", fontsize=12)
plt.grid(True)
plt.show()
