from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product

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

T = int(input())
debug = False
for it in range(T):
    n = int(input())
    t = []
    freq = []
    target = [0]*2
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

    maxLen = 2
    cnt = n - 1 
    n = len(t)

    sumFreq = [0]

    for i in range(n):
        sumFreq.append(sumFreq[-1] + freq[i])

    for l in range(n-1):
        update(freq[l+1] + freq[l]) 

    if debug:
        print("newn:", n, "sumFreq:", sumFreq)
        print(t)
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
        update(sumFreq[r] - sumFreq[l]) #l..r-1  -> 第sum r-1  - sum[l-1] 

    print("Case #%d: %d %d"%(it+1, maxLen, cnt))
    