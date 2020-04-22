from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
"""
N: j++ W

E: i++ W

小： 暴力打表
大： 分解 目标： 最多32步骤
     把 x y 的二分解出来 

22'30 ok
"""

global f, tr, dx, dy

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
tr = {'N':0, 'S':1, 'E':2, 'W':3}

def dfs(step, cur, x, y):
    global f, tr, dx, dy
    assert(step==len(cur))
    if (abs(x)>100 or abs(y)>100):
        return
    if f[x][y]=='_' or len(f[x][y])>step:
        f[x][y] = cur
    if step<10:
        for i,c in enumerate('NSEW'):
            dfs(step+1, cur + c, x + (dx[i] << step), y + (dy[i]<<step))


T = int(input())

f = [["_"]*201 for _ in range(201)]

f[0][0] = ""

dfs(0,"",0,0)

for it in range(T):
    x, y = map(int, input().split())
    
    ans = f[x][y]
    if ans == '_':
        ans = "IMPOSSIBLE"
    print("Case #%d: %s"%(it+1, ans))
