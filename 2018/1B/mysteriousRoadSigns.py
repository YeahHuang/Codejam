from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
from random import randint
"""
10min 读题

1:53 - 1:45 玩儿了 
然后5min 泡了咖啡

S road signs on both sides 
Di km east of start
Ai face west
Bi fase east

都是无用信息的bb

关键的： 子序列满足 Di + Ai = M
Di - Bi = N m n 不一定要相同


小： s<=100
大： s<=1e5


最小的直接most common 一下？
n*n 肯定有解 可以试一试 如果两头指针的话 会怎么样

1:36 - 

s = 1
s = 2
freq 后刚好是3个的

6:11 大的tle
一个是如果和前面的best 均相等 那么肯定不是了
一个是如果 i == i-1 那么 肯定不能选这个k
"""

global cnt, maxLen

def update(length):
    global cnt, maxLen
    if length >2:
        if length == maxLen:
            cnt += 1
        elif length > maxLen:
            maxLen = length
            cnt = 1
test = False
debug = False
if test:
    T = 1
else:
    T = int(input())

for it in range(T):
    if test:#写了这个间隔的test之后就知道自己错在哪里了 
        n = 20
        t = [[i,i] for i in range(20)]
        for i in range(10):
            t[i*2][0] = 10
            t[i*2+1][1] = 3
        freq = [1] * 20 
    else:   
        n = int(input())
        t = []
        freq = []
        for i in range(n):
            d, a, b = map(int, input().split())
            if t and d+a == t[-1][0] and d-b == t[-1][1]:
                freq[-1] += 1
            else:
                t.append([d+a, d-b])
                freq.append(1)
        if len(t)<=2:
            print("Case #%d: %d 1"%(it+1, sum(freq)))
            continue

    target = [0]*2
    maxLen = 2
    cnt = n - 1 
    n = len(t)

    sumFreq = [0] #length = n + 1

    for i in range(n):
        sumFreq.append(sumFreq[-1] + freq[i])

    # for l in range(n-1):
    #     update(freq[l+1] + freq[l]) 
    prev = [[0,0,0],[0,0,0]]
    for l in range(n-1):
        tmp = [] 
        # if sumFreq[n] - sumFreq[l] < maxLen:
        #     break
        for k in range(2):
            if l and t[l][k] == t[l-1][k]:
                tmp.append(prev[k])
                if (debug):
                    print("skip same l=%d k=%d"%(l,k))
                continue
            target[k] = t[l][k]
            r = l + 1
            while r < n and t[r][k] == t[l][k]:
                r += 1
            if r < n:    
                target[1-k] = t[r][1-k]
                #target[1-k] == t[r][1-k] WA
                if debug:
                    print("prev: ",prev[1-k], "target: ", target)
                if l and target[0] == prev[1-k][1] and target[1] == prev[1-k][2]:
                    if debug:
                        print("skip l=%d k=%d"%(l,k))
                    tmp.append(prev[1-k])
                    continue
                while r < n:
                    if not(t[r][0] == target[0] or t[r][1] == target[1]):
                        break
                    r += 1
            if debug:
                print("l=%d r=%d m=%d n=%d"%(l,r,target[0],target[1]))
            tmp.append([r, target[0], target[1]])
            #maxi = max(maxi, sumFreq[r] - sumFreq[l]) #l..r-1  r <= n 
        if tmp[0][0] > tmp[1][0]:
            update(sumFreq[tmp[0][0]] - sumFreq[l])
        else:
            update(sumFreq[tmp[1][0]] - sumFreq[l])
        prev = tmp.copy()


    if debug:
        print("newn:", n, "sumFreq:", sumFreq)
        print(t)
    
    
    print("Case #%d: %d %d"%(it+1, maxLen, cnt))
    
"""
for l in range(n-1):
        maxi = 0
        if sumFreq[n] - sumFreq[l] < maxLen:
            break
        for k in range(2):
            target[k] = t[l][k]
            r = l + 1
            while r < n and t[r][k] == t[l][k]:
                r += 1
            if r == n:
                maxi = max(maxi, sumFreq[r] - sumFreq[l])
                #update(sumFreq[r] - sumFreq[l]) #最后一个 减去 [l-1+1] #这里写错了 WA 
                continue
            else:
                target[1-k] = t[r][1-k]
                #target[1-k] == t[r][1-k] WA
            while r < n:
                if not(t[r][0] == target[0] or t[r][1] == target[1]):
                    break
                r += 1
            if debug:
                print("l=%d r=%d m=%d n=%d"%(l,r,target[0],target[1]))
            maxi = max(maxi, sumFreq[r] - sumFreq[l]) #l..r-1  r <= n 
        update(maxi)


    for l in range(n-3):
        if freq[l] > 1:
            hyh=1
        elif freq[l+1] > 1:
            hyh=2
        else:
            for k in range(2):
                r = l + 1
                while r<n:
                    if t[r][k] == t[l][k]:
                        r += 1
                    else:
                        break
                if r > l + 1 and r < n:
                    target[k] = t[l][k]
                    target[1-k] = t[r][1-k]
                    break

            if r == l + 1:
                if r == n-1:
                    if debug:
                        print("l=%d r=%d m=%d n=%d"%(l,r,target[0],target[1]))
                    #update(sumFreq[r] - sumFreq[l])
                    #continue
                else:
                    cc = [defaultdict(), defaultdict()]
                    for i in range(l,l+3):
                        for j in range(2):
                            if t[i][j] in cc[j].keys():
                                cc[j][t[i][j]] += freq[i]
                            else:
                                cc[j][t[i][j]] = freq[i]
                    for j in range(2):
                        maxv = -1
                        for k, v in cc[j].items():
                            if v > maxv:
                                target[j] = k
                                maxv = v
                #nt = [[t[i][j] for i in range(l, l+3)]  for j in range(2)]
                # if debug:
                #     print("transformed: ",nt)
                    
                #target = [Counter(nt[0]).most_common()[0][0], Counter(nt[1]).most_common()[0][0]]

        while r < n:
            if not(t[r][0] == target[0] or t[r][1] == target[1]):
                break
            r += 1
        if debug:
            print("l=%d r=%d m=%d n=%d"%(l,r,target[0],target[1]))
        if r <= n:
            update(sumFreq[r] - sumFreq[l]) #l..r-1  -> 第sum r-1  - sum[l-1] 
"""