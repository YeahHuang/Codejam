from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
import random
import sys

global debug, test
"""
X,y, (east, north) string of characters M 
ans = the smallest number of minutes

可以二分 因为肯定

直接暴力？

N y++ S --
E x++ W x--
看dist在不在范围内
for i in range(m):
 maxi_steps = i+1
"""

def solve(x, y, s):
    global debug, test
    dx = [0,  0, 1,-1]
    dy = [1, -1, 0, 0]
    d = {'N':0, 'S':1, 'E':2, 'W':3}
    for i, c in enumerate(s):
        x, y = x + dx[d[c]], y + dy[d[c]]
        if abs(x) + abs(y) <= i + 1:
            return str(i+1)
    return "IMPOSSIBLE"



T = int(input())
debug = True
test = True
for it in range(T):
    x, y, s = input().split()
    ans = solve(int(x), int(y), s)
    print("Case #%d: %s"%(it+1, ans))