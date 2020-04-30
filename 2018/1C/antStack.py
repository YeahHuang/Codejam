from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
"""
T
N
w1..wn    the weight in milligrams of the i-th ant
长度严格上升
小： Wi [1,1000] 6 case N = 100 其他的T-6 N [2,50]
大：  Wi [1,1e9] 6 case N = 1e5 其他的T-6 N [2,500]

它上头的和 <= 6 weight it self 

小的： 哈希wi + dfs？ 

大的： 二分数量？ or dp？ 

5:20 - 5:28 

dp[i][j] 到前i个 我pick了j层 

if w[i]*6 >= dp[i-1][pick-1] 
    dp[i][pick] =  min(dp[i-1][pick], dp[i-1][pick-1] + w)



6:27 - 6:37 submit  大的会MLE

6:43 改成了pre cur 的版本 submit 大的会TLE   solve_large()
    说明T=100 其中6个 N=1e5 * 1e3 左右是会TLE的 15s限时

7:23 写成了 有限制的pre版本 solve_extra_large 
   mLen = 50 WA
7:25 mLen = 500 TLE
7:27 mLen = 200 TLE
7:29 mLen = 100 AC!!!!!! 

像这种i+1 由i决定 怕影响的可以倒着写 参考Syloviaely-antStack.cpp  for  for (int j=lim;j>=0;j--)
            if (dp[j]<=6ll*w[i]) dp[j+1]=min(dp[j+1],dp[j]+w[i]);
"""
global debug

def solve_small(n, w):
    global debug
    maxi_pick = 1
    dp = [[0] * (n+1) for _ in range(n)]
    dp[0][1] = w[0]
    for i in range(1, n):
        for pick in range(1, maxi_pick+1):
            if w[i]*6 >= dp[i-1][pick-1]:
                dp[i][pick] =  min(dp[i-1][pick], dp[i-1][pick-1] + w[i])
            else:
                dp[i][pick] = dp[i-1][pick]
        if w[i]*6 >= dp[i-1][maxi_pick]:
            dp[i][maxi_pick+1] = dp[i-1][maxi_pick] + w[i]
            maxi_pick += 1
    return maxi_pick 

def solve_large(n, w):
    global debug
    maxi_pick = 1
    pre = [0,w[0]]
    for i in range(1, n):
        cur = pre.copy()
        for pick in range(1, maxi_pick+1):
            if w[i]*6 >= pre[pick-1]:
                cur[pick] =  min(pre[pick], pre[pick-1] + w[i])
        if w[i]*6 >= pre[maxi_pick]:
            cur.append(pre[maxi_pick]+w[i])
            maxi_pick += 1
        pre = cur.copy()
    return maxi_pick 

def solve_extra_large(n, w): #n*n 
    global debug
    if debug:
        print("Extra large", n)
    maxi_pick = 1
    MAXI = float('inf')
    pre = [0,w[0]]
    mLen = 100
    start = n 
    for i in range(1, n):
        pre.append(MAXI)
        pre = [min(pre[j], (pre[j-1]+w[i]) if w[i]*6 >= pre[j-1] else MAXI) if j else 0 
         for j in range(maxi_pick+2)]
        if pre[-1] == MAXI:
            pre.pop()
        else:
            maxi_pick += 1
            if maxi_pick >= mLen:
                start = i + 1
                break
    if maxi_pick>=mLen:
        if debug:
            print(">=mLen, start=%d"%start)
        for i in range(start, n):
            if w[i]*6 < pre[mLen]:
                pre = [min(pre[j], (pre[j-1]+w[i]) if w[i]*6 >= pre[j-1] else MAXI) if j else 0 
         for j in range(mLen+1)]
            else:
                maxi_pick += 1
                pre = [min(pre[j+1] if j+1<mLen else MAXI, (pre[j]+w[i]) if w[i]*6 >= pre[j] else MAXI) if j else 0 
                for j in range(mLen+1)]


        # cur = pre.copy()
        # for pick in range(1, maxi_pick+1):
        #     if w[i]*6 >= pre[pick-1]:
        #         cur[pick] =  min(pre[pick], pre[pick-1] + w[i])
        # if w[i]*6 >= pre[maxi_pick]:
        #     cur.append(pre[maxi_pick]+w[i])
        #     maxi_pick += 1
        # pre = cur.copy()
    return maxi_pick 


debug = False
test = False
if test:
    T = 1
else:
    T = int(input())
for it in range(T):
    if test:
        n = 100000
        w = [i+1 for i in range(n-1)] 
        w.append(int(1e9))
    else:
        n = int(input())
        w = list(map(int, input().split()))
    if n == int(1e5):
        ans = solve_extra_large(n, w)
    else:
        ans = solve_large(n, w)

    print("Case #%d: %d"%(it+1, ans))