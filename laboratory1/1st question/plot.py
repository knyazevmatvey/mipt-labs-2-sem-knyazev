import matplotlib.pyplot as plt
import numpy

max_n = 199;
t = []
for i in range(max_n):
    times = [int(x) for x in input().split()]
    print(len(times))
    times = numpy.array(times)
    average = times.sum()/len(times)
    print(average)
    t.append(average)
n = []
for i in range(max_n):
    n.append(i+1)
    
plt.plot(n, t)
plt.xlabel('Рамер сетки')
plt.ylabel('Среднее время')
plt.title('Зависимость среднего времени от размера решетки')
plt.savefig('График.png', dpi = 1200)
plt.show()
