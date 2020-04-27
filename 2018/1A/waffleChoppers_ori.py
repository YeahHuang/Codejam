from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
import numpy as np 
"""
迟到5min
2:25 - 1:51 
R,C, H, V

R lines 每一行c个 t[i][j] @有 . 空

Case #x: y    POSSIBLE / IMPOSSIBLE

sum % (h+1)*(v+1) !=0 fail 
直接暴力模拟 每一列的和 一定刚好是 sum % (v+1)

每一块行的和 一定刚好是 sum % (h+1)

1:17 runtime error
"""
def trans(c):
    return int(c=='@')

T = int(input())

debug = True

for it in range(T):
    r, c, h, v = map(int, input().split())
    t = []
    summ = 0 
    
    for i in range(r):
        tmp = list(map(trans,list(input())))
        summ += sum(tmp)
        t.append(tmp)
    if summ % ((h+1)*(v+1)) != 0:
        ans = "IMPOSSIBLE"
        print("Case #%d: %s"%(it+1, ans))
        continue
    if summ == 0:
        ans = "POSSIBLE"
        print("Case #%d: %s"%(it+1, ans))
        continue
    sumh = summ // (h+1)
    flag, i, cutH = True, 0, [-1]
    while i < r:
        j = i
        tmpS = 0
        while j < r:
            tmpS += sum(t[j])
            if tmpS == sumh:
                cutH.append(j)
                break
            elif tmpS > sumh:
                flag = False
                break
            j += 1
        if flag==False:
            break
        i = j + 1

    if flag == False:
        ans = "IMPOSSIBLE"
        print("Case #%d: %s"%(it+1, ans))
        continue
    

    sum0, sumv, i, cutV, tt = summ // (v+1) // (h+1), summ // (v+1), 0, [-1], [zip(*t)]
    while i < c:
        j = i
        tmpS = 0 
        while j < c:
            tmpS += sum(tt[j])
            if tmpS == sumv:
                cutV.append(j)
                break
            elif tmpS > sumv:
                flag = False
                break
            j += 1
        if flag==False:
            break
        i = j + 1

    if flag == False:
        ans = "IMPOSSIBLE"
        print("Case #%d: %s"%(it+1, ans))
        continue


    if debug:
        print(t)
        print("cutV", cutV)
        print("cutH", cutH)
        print("sumv=%d sumh=%d"%(sumv,sumh))


    #if len(cutH)!=(h+2) or len(cutV)!=(v+2) 原来这么写的时候会RE
    if len(cutH)!=(h+2) or len(cutV)!=(v+2) or cutH[-1]!=r-1 or cutV[-1]!=c-1:
        ans = "IMPOSSIBLE"
        print("Case #%d: %s"%(it+1, ans))
        continue

    for ii in range(h+1):
        tmp = t[cutH[ii]+1: cutH[ii+1] + 1]
        for jj in range(v+1):
            tmpS = 0
            for line in tmp:
                tmpS += sum(line[cutV[jj]+1: cutV[jj+1]+1])
            if debug:
                print(tmpS)
            if tmpS != sum0:
                flag = False
                break
        if flag == False:
            break
    if flag:
        ans = "POSSIBLE"
    else:
        ans = "IMPOSSIBLE"
                    
    print("Case #%d: %s"%(it+1, ans))





