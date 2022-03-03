import matplotlib.pyplot as plt
import numpy

max_n = 99;
t = []
for i in range(max_n):
    times = [int(x)-1 for x in input().split()]
    print(len(times))
    times = numpy.array(times)
    average = times.sum()/len(times)
    print(average)
    t.append(average)
n = []
for i in range(max_n):
    n.append(i+1)
    
plt.plot(n, t)
plt.xlabel('Размер')
plt.ylabel('Среднее время')
#plt.xlim([0,80])
plt.title('Зависимость времени от количества дислокаций')
plt.ylim([0, numpy.max(t)*1.1])
plt.savefig('График.png', dpi = 1200)
plt.show()
