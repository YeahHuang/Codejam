from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
"""
interactive
T = 50 N = 200(顾客数量)
D [0,N] 25s


maxi sell M 棒棒糖 
实际sell的需要 > 90%M

感觉可以暴力 + 随机？

5:07 - 5:20 interactive

"""
import sys
import random
global debug

T = int(input())

debug = True
test = True
out = open('hyh.txt','w') 
print("", file=out)
for it in range(T):
    n = int(input())
    has = [True]*n
    cnt = [0] * n
    for hyh in range(n):
        p = list(map(int, input().split()))
        if p[0] == -1:
            break
        #given = False
        possible = []
        for i in p[1:]:
            if has[i]:
                possible.append(i)
                cnt[i] += 1
        if len(possible)==0:
            print(-1)
            sys.stdout.flush()
        else:
            #random.shuffle(possible) 这个加不加都能过 
            mini = float('inf')
            for i in possible:
                if cnt[i] < mini:
                    mini = cnt[i]
                    idx = i
            print(idx)
            sys.stdout.flush()
            has[idx] = False
            # idx = random.randint(0, len(possible)-1)
            # print(possible[idx])
            # has[possible[idx]] = False

        #if given == False:
            
