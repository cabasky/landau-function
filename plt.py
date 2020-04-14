from matplotlib import pyplot as plt
from matplotlib import font_manager
from math import log

op=open("op2","r")
src=[log(int(i),2) for i in op.read().split("\n")]
op.close()

plt.plot(src,linewidth=1)
plt.xlabel("n")
plt.ylabel("log[g(n)] Landau function")
plt.show()