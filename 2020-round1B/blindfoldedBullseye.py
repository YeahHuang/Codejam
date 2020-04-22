from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
import sys
"""

12:22 - 40 最小的


"""


def hyh(x, y, x0, y0, r):
    return (x-x0)**2 + (y-y0)**2 <= r**2

T, a, b = map(int, input().split())
debug = True

R = 10**9



if debug:
    out = open('hyh.txt','w') 
for it in range(T):
    flag = False
    if a == R - 5:
        for x in range(-5, 6):
            if flag:
                break
            for y in range(-5, 6):
                print("%d %d"%(x,y))
                s = input()
                if s == "CENTER":
                    flag = True
                    break
    elif a == R-50:
        xs = [0, 1, -1]
        ys = [0, 1, -1]

        tmp = [999999949, 999999962, 999999974, 999999986, 999999999]
        for num in tmp:
            ask.append(tmp)
            ask.append(tmp+1)
            ask.append(tmp-1)
            ask.append(-tmp)
            ask.append(-tmp-1)
            ask.append(-tmp+1)
        ask.sort()

        flagX = []
        for i in ask:
            print("%d %d"%(i, 0))
            sys.stdout.flush()
            s = input()
            if s=='MISS':
                flagX.append(False)
            else:
                flagX.append(True)

        for j, i in enumerate(ask):
            if i < 0 and flagX[j]:
                ll = i + R
                for k in range(j, len(ask)):
                    if flagX[k] == False:
                        break
                break


        sys.stdout.flush()
        s = input()
        if s == "MISS":
            rx = True
        print("%d %d"%( 0, R-51))
        sys.stdout.flush()
        s = input()
        if s == "MISS":
            ry = True

        for x in xs:
            if flag:
                break
            for y in ys:
                print("%d %d"%(x,y))
                s = input()
                if s == "CENTER":
                    flag = True
                    break


    if debug:
        print("", file=out)

