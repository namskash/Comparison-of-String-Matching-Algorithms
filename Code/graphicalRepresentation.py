f = open("../Outputs/englishNaive_t.txt")
line = f.read().split(',')[:-1]
line = [int(x) for x in line]

print(line)

import matplotlib.pyplot as plt
import numpy as np

xpoints = np.array([x for x in range(len(line))])
ypoints = np.array(line)

plt.plot(xpoints, ypoints)
plt.show()