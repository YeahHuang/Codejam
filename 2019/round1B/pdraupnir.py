import numpy as np
import sys
T, w = map(int, input().split())
#w = int(input())
for it in range(T):
    r = []
    for i in range(6):
        print(i+1)
        sys.stdout.flush()
        r.append(int(input()))
    #r = [22, 26, 33, 49, 70, 122]
    #print(r)
    A = np.array([
        [2, 1, 1,1,1,1], 
        [4, 2, 1,1,1,1], 
        [8, 2, 2,1,1,1], 
        [16,4, 2,2,1,1], 
        [32,4, 2,2,2,1], 
        [64,8, 4,2,2,2]])
    b = np.array(r)
    x = np.linalg.solve(A, b)
    #print(x)
    while len(x) < 6:
        x.append(0)
    s = "";
    for i in range(5):
        s += str(int(round(x[i]))) + " "
    s += str(int(round(x[5])))
    print(s)
    sys.stdout.flush()
    res = int(input())
    if res==-1:
        break
