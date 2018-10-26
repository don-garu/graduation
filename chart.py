# charting result

try:
    f = open("/home/jjun/graduation/result/result.txt", 'r')
    #fill in
    s1 = f.readline()
    tok1 = s1.split(',')
    tok1[2] = tok1[2][:-1]

    s2 = f.readline()
    tok2 = s2.split(',')
    tok2[2] = tok2[2][:-1]

    #print(tok1)
    #print(tok2)
finally:
    f.close()

import numpy as np
import matplotlib.pyplot as plt
 
# data to plot
n_groups = 1
per_parallel = (float(tok1[2]) * 1000)
per_sequential = (float(tok2[2]) * 1000)
 
# create plot
fig, ax = plt.subplots()
index = np.arange(n_groups)
bar_width = 0.25
opacity = 0.3
 
rects1 = plt.bar(index, per_parallel, bar_width,
                 alpha=opacity,
                 color='b',
                 label=tok1[0])
 
rects2 = plt.bar(index + bar_width, per_sequential, bar_width,
                 alpha=opacity,
                 color='g',
                 label=tok2[0])
 
plt.xlabel(tok1[1] + ' of Nodes')
plt.ylabel('Time in millisec')
plt.title('Performance Compare')
plt.xticks(index + bar_width / 2, ' ')
plt.legend()
 
plt.tight_layout()
#plt.show()
plt.savefig('/home/jjun/graduation/result/chart.png')