import numpy as np
import matplotlib.pyplot as plt
import math


n_max = 40+1
max_time = [0 for i in range(n_max)]
indices = [0 for i in range(n_max)]

for n in range(1, n_max):
    f = open('data(n='+str(n)+').txt')
    times = [0]
    for line in f:
        time = np.array([int(x) for x in line.split()])
        average = np.mean(time)
        times.append(average)
    f.close()
    
    t_max = max(times)
    index = 0
    while (times[index] != t_max):
        index += 1

    max_time[n] = t_max
    indices[n] = index

axis = []
for i in range(1, n_max+1):
    axis.append(i)

plt.plot(axis, max_time)
plt.title('Высота пика от размера сетки')
plt.xlabel('Размер сетки')
plt.ylabel('Высота пика')
plt.savefig('Высота пика от размера сетки', dpi=1200)
plt.show()

plt.plot(axis, indices)
plt.title('Положение пика то размера сетки')
plt.xlabel('Размер сетки')
plt.ylabel('Положение пика')
plt.savefig('Положение пика то размера сетки', dpi=1200)
plt.show()

ln_time = []
axis_for_ln = []
for i in range(n_max):
    if (max_time[i] != 0):
        axis_for_ln.append(math.log(i+1))
        ln_time.append(math.log(max_time[i]))
        print(math.log(i+1), math.log(max_time[i]))
plt.plot(axis_for_ln, ln_time)
plt.title('ln(t) ln(n)')
plt.xlabel('ln(n)')
plt.ylabel('ln(max)')
plt.savefig('ln максимума от  ln размера сетки', dpi=1200)
plt.show()



    
    
        
