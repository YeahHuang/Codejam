from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product

"""
11min读题
R 石头 > S 剪刀 > P 布

> 1e100 会fair coin

n = 2**k 0..n01

0&1 2&3 .... n-2&n-1

T a(other robots) = 2**k - 1(k>=1)

win所有

小的 1<=a<=7 长度<=5

大的 1<=a<=255 长度<=500

返回<=500

直接暴力 每一位3种可能 最多2**500 其实加上排除可能不止 

8:11 ac 1h
"""



T = int(input())

for it in range(T):
    n = int(input())
    c = set()
    win = {'R':'P', 'S':'R', 'P':'S'};

    for i in range(n):
        s = input()
        ss = ""
        while len(ss) < 500:
            ss += s
        c.add(ss[:500])
    
    ans = ""
    for i in range(500):
        cur = set()
        for s in c:
            cur.add(s[i])
        if len(cur) == 3:
            ans = "IMPOSSIBLE"
            break
        elif len(cur) == 1:
            ans += win[list(cur)[0]]
            break
        else:
            p1, p2 = list(cur)[0], list(cur)[1]
            if p1 == win[p2]:
                ans += p1
            else:
                ans += p2
            c1 = set()
            for s in c:
                if s[i] == ans[-1]:
                    c1.add(s)
            c = c1.copy()


    print("Case #%d: %s"%(it+1, ans))
