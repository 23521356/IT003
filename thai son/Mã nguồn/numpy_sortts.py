import numpy as np
N=int(input())
ar=list(map(int,input().split()))
ar = np.sort(ar)
for i in range(0, N) :
	print(ar[i], end = ' ')