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
global debug

def trans(c):
    return int(c=='@')

def calCutPoint(t, r, sum0):

    flag, i, cut = True, 0, []
    while i < r:
        j = i
        tmpS = 0
        while j < r:
            tmpS += sum(t[j])
            if tmpS == sum0:
            #if tmpS == sumh:
                cut.append(j)
                break
            elif tmpS > sum0:
            #elif tmpS > sumh:
                flag = False
                break
            j += 1
        if flag==False:
            break
        i = j + 1
    return flag, cut

debug = True
test = True

T = int(input())

"""
3 8 1 2
@..@.@@.
.@.@....
@@@.@.@@
3 5 1 1
@..@.
.@.@.
@@@.@
5 3 1 1
@.@
.@@
..@
@@.
..@
"""
for it in range(T):
    r, c, h, v = map(int, input().split())
    t = [list(map(trans, list(input()))) for _ in range(r)]
    summ = sum(map(sum, t))
    if summ % ((h+1)*(v+1)) != 0:
        flag = False
    elif summ == 0:
        flag = True
    else:

        sumh, sumv, sum0 = summ // (h+1), summ // (v+1), summ // (v+1) // (h+1)
        flag, cutH = calCutPoint(t, r, sumh)

        if flag == True:
            flag, cutV = calCutPoint([*zip(*t)], c, sumv)
            #if len(cutH)!=(h+2) or len(cutV)!=(v+2) 原来这么写的时候会RE
            if len(cutH)!=(h+1) or len(cutV)!=(v+1) or cutH[-1]!=r-1 or cutV[-1]!=c-1:
                flag = False
            if flag:
                hyh = [[0] * (v+1) for _ in range(h+1)]
                idx = 0
                hh = [0] * h
                vv = [0] * v
                while i < h:
                    if i > cutH[idx]:
                        idx += 1
                    hh[i] = idx
                    i += 1
                while j < c:
                    if j > cutV[idx]:
                        idx += 1
                    vv[j] = idx
                    j += 1

                

                # for ii in range(h+1):
                #     tmp = t[cutH[ii]+1: cutH[ii+1] + 1].copy()
                #     for jj in range(v+1):
                #         tmpS = 0
                #         for line in tmp:
                #             tmpS += sum(line[cutV[jj]+1: cutV[jj+1]+1])
                #         if tmpS != sum0:
                #             flag = False
                #             break
                #     if flag == False:
                #         break

        if debug:
            print(t)
            print("cutV", cutV)
            print("cutH", cutH)
            print("summ=%d sumv=%d sumh=%d sum0=%d"%(summ,sumv,sumh, sum0))

    if flag:
        ans = "POSSIBLE"
    else:
        ans = "IMPOSSIBLE"
                    
    print("Case #%d: %s"%(it+1, ans))

        # flag, i, cutH = True, 0, [-1]
        # while i < r:
        #     j = i
        #     tmpS = 0
        #     while j < r:
        #         tmpS += sum(t[j])
        #         if tmpS == sumh:
        #             cutH.append(j)
        #             break
        #         elif tmpS > sumh:
        #             flag = False
        #             break
        #         j += 1
        #     if flag==False:
        #         break
        #     i = j + 1
        # sum0, sumv, i, cutV, tt = summ // (v+1) // (h+1), summ // (v+1), 0, [-1], [*zip(*t)]
        # while i < c:
        #     j = i
        #     tmpS = 0 
        #     while j < c:
        #         tmpS += sum(tt[j])
        #         if tmpS == sumv:
        #             cutV.append(j)
        #             break
        #         elif tmpS > sumv:
        #             flag = False
        #             break
        #         j += 1
        #     if flag==False:
        #         break
        #     i = j + 1

        # if flag == False:
        #     ans = "IMPOSSIBLE"
        #     print("Case #%d: %s"%(it+1, ans))
        #     continue






