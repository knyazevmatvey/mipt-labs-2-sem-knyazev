import matplotlib.pyplot as plt
import numpy

times = [int(x) for x in input().split()]
bins = numpy.arange(0, 30)
plt.hist(times, bins)
plt.savefig('picture.png', dpi=1200)
plt.show()
