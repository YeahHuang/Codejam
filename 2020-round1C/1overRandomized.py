from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
import random
import sys

global debug, test
"""
Ui  
1e4 lines follow    Qi Ri   ith query and response
output: Case #1: TPFOXLUSHB
5:16 - 5:25 看不懂sample 长度不同？

1:32 提交 有随机的可能 可以考虑写小的 
"""
def solve_small():
    global debug, test
    counter = defaultdict()
    r = []
    for i in range(int(1e4)):
        q, s = input().split()

        c = s[0]
        counter[c] = counter.get(c, 0) + 1
        # for c in s:
        #     counter[c] = counter.get(c, 0) + 1
        r.append(s)

    
    hyh = [(v, k) for k, v in counter.items()]
    hyh.sort(reverse=True)
    if debug:
        print(counter)
        print("sorted:", hyh)
    ans = "".join([k for (v,k) in hyh])
    #ans = ans[-1] + ans[:-1]
    for s in r:
        for c in s:
            if c not in counter.keys():
                ans = c + ans
                return ans
    return ans

def solve_large():
    global debug, test
    counter = defaultdict()
    r = []
    for i in range(int(1e4)):
        q, s = input().split()
        c = s[0]
        counter[c] = counter.get(c, 0) + 1
        # for c in s:
        #     counter[c] = counter.get(c, 0) + 1
        r.append(s)

    hyh = [(v, k) for k, v in counter.items()]
    hyh.sort(reverse=True)
    if debug:
        print(counter)
        print("sorted:", hyh)
    ans = "".join([k for (v,k) in hyh])
    ans = ans[-1] + ans[:-1]
    return ans
T = int(input())
debug = False
test = True
for it in range(T):
    u = int(input())
    ans = solve_small()
    # if u == 2:
    #     ans = solve_small()
    # else:
    #     ans = solve_large()
    print("Case #%d: %s"%(it+1, ans))