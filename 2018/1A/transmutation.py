from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
"""
每条边 反向 每个都有时间戳

所以1指向的边 肯定不要了

每一个的输入边的度 <= 2

M
m more lines Ri1, Ri2 > i
g1..gm current gram 

dfs 不能利用已经visit的 直系father

还剩1‘11 的时候 开始看解答
"""
global visited

def dfs(step):
    r1, r2 = t[step][0], t[step][1]
    if visited[r1] == False and visited[r2] == False:
        g[step] += min(g[r1], g[r2])

T = int(input())

for it in range(T):
    m  = int(input())
    t = [[int(x)-1 for x in input().split()] for _ in range(m)]
    # for i in range(m):
    #     r1, r2 = map(int, input().split())
    #     t.append([r1-1, r2-1])
    g = list(map(int, input().split()))
    visited = [False] * m
    visited[0] = True
    dfs(0)

    print("Case #%d: %d"%(it+1, ans))


"""

    dfn, low, father = [-1]*n, [-1]*n, [-1]*n
    t = collections.defaultdict(list)
    self.time_stamp = 0
    for c in connections:
        t[c[0]].append(c[1])
        t[c[1]].append(c[0])
    ret = []

    def dfs(idx):
        self.time_stamp += 1 #WA一次 一开始以为可以自动默认global了 结果还是需要加self. 的
        low[idx] = dfn[idx] = self.time_stamp 
        for child in t[idx]:
            if dfn[child]==-1:
                father[child] = idx
                dfs(child)
            if child != father[idx]:
                low[idx] = min(low[idx], low[child])

"""
