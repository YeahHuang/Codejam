from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product

"""

12:40 - 

s first 

R increasing

r, s
4 2 12341234   11223344

2 3 121212   111222

虽然看数据量觉得会WA 可能可以暴力dfs + memo？
"""

global target, ans, debug

def dfs(idx, cur, steps):
    global ans, debug, target
    if (debug):
        print(idx, cur)
        print(steps)
    if len(steps)>=len(ans):
        return

    if (idx<=0):
        ans = steps.copy()
        return

    for k in range(idx-1, -1, -1):
        if cur[k] == target[idx-1]:
            swap = k
            nex = cur[swap+1:] + cur[:swap+1]
            steps.append((swap+1, idx - swap - 1))
            newIdx = idx
            while newIdx >= 1 and nex[-1] == target[newIdx-1]:
                newIdx -= 1
                nex.pop()
            dfs(newIdx, nex, steps)
            steps.pop()



debug =  False
test = True


tests = [(3,2),(3,3),(3,4), (2, 3), (3,3),(4,3)]
for s in range(2,8):
    tests.append((2,s))

for r in range(2,6):
    tests.append((r,2))

if test:
    T = len(tests)
else:
    T = int(input())
for it in range(T):
    if test:
        r, s = tests.pop()
    else:
        r, s = map(int, input().split())
    cur = []
    n = r * s
    for i in range(s):
        for j in range(r):
            cur.append(j+1)


    target = []
    for i in range(r):
        for j in range(s):
            target.append(i+1)

    if debug:
        print(cur)
        print(target)

    ans = []   
    idx = r*s-1 #[idx:..] has been matched
    cur.pop()
    
    while idx > 0:
        for k in range(idx-1, -1, -1):
            if cur[k] == target[idx-1]:
                swap = k
                break
        cur[:] = cur[swap+1:] + cur[:swap+1] #其实只用加到swap就行
        ans.append((swap+1, idx - swap - 1)) #(idx-1) - (swap+1) + 1 = idx - swap - 1
        while idx >= 1 and cur[-1]==target[idx-1]:
            idx -= 1
            cur.pop()
        if debug:
            print(idx, cur)
            print(ans)

    cur = []
    n = r * s
    ans0 = ans.copy()
    for i in range(s):
        for j in range(r):
            cur.append(j+1)
    idx = r*s-1 #[idx:..] has been matched
    cur.pop()
    dfs(idx, cur, [])

    if test:
        if len(ans0)!=len(ans):
            print("Differs when r=%d s=%d"%(r,s))
            print("Case #%d: %d"%(it+1, len(ans)))
            for tmp in ans:
                print("%d %d"%(tmp[0], tmp[1]))
            print("Case #%d: %d"%(it+1, len(ans0)))
            for tmp in ans0:
                print("%d %d"%(tmp[0], tmp[1]))
        else:
            print("r=%d s=%d steps=%d"%(r,s,len(ans)))
    if test==False:
        print("Case #%d: %d"%(it+1, len(ans)))
        for tmp in ans:
            print("%d %d"%(tmp[0], tmp[1]))
