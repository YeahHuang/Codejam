from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
import random
import sys
from math import gcd

global debug, test
"""
5:26 - 5:38 读题 想晓得

6:07 最小的WA了
n(number of slices) d(dinner number)
a1..an  the internal angle (in nanodegrees) of the i-th slice.
ans:  the smallest number of cuts you need



300 3
300 50
最大的 n到1000 甚至 10000
n = 1 ans = d - 1

most_common(0)[1] >= D? return 0

d = 2 没有重复的那必然是1刀
d = 3 edge test case 俩刚好是最大的 其他弄不了
      按照cnt 从大到小 然后number 从小到大排序
      
      取当前 能过肯定OK了 sort 一下 大概知道自己爹位置 
      num * d  或者直接验证也行 每一个减
      edge test case n = 2 俩刚好是最大的 其他弄不了


6:46 - 

6:50 TLE
      
"""

# def getMinCount(cnt, num, counter, d):
#     global debug
#     served = cnt
#     cut_cnt = 0
#     for (num2, cnt2) in counter:
#         if True:
#         #if num2!=num:
#             if num2%num == 0:
#                 for i in range(abs(cnt2)):
#                     if served + num2//num <= d:
#                         served += num2//num
#                         cut_cnt = num2//num - 1 
#                     else:
#                         break
#     cut_cnt += (d - served)
#     if debug:
#         print("getMinCount() target num = %d, original cnt=%d, cut_cnt = %d"%(num, cnt, cut_cnt))
#     return cut_cnt

def getMinCount( num, counter, d):
    global debug
    served = 0
    cut_cnt = 0
    for (num2, cnt2) in counter:
        if num==10 and debug:
            print("Currently looking at num=%d cnt=%d"%(num2, cnt2))
        if True:
        #if num2!=num:
            if num2%num == 0:
                if num==10 and debug:
                    print("Could Mod! num2//num=%d"%(num2//num))
                for i in range(abs(cnt2)):
                    if served + num2//num <= d:
                        served += num2//num
                        cut_cnt += num2//num - 1 
                    else:
                        break
    if num==10 and debug:
        print("already served %d left=%d"%(served, d-served))
    cut_cnt += (d - served)
    if debug:
        print("getMinCount() target num = %d, cut_cnt = %d"%(num, cut_cnt))
    return cut_cnt

def solve_large(n, d, a):
    """
    RE: n < d?
        直接枚举所有的num append(1)
    如果 sum() 都小的话 那只能 把每一个都double着看看

    20 5 
    [20,30,40 1e5, 1e5..]
    output: 6 

    每一个num 公约数也带进去算一算 a能到1e9 可以二分a嘛emmm
    """
    global debug, test
    if n == 1:
        return d-1
    if n == 2 and d == 3:
        if a[0]==a[1]:
            return 2
        if a[0]%a[1] == 0 or a[1]%a[0] == 0:
            return 1
        else:
            return 2
    
    #n >= d only integer accepted
    
    if Counter(a).most_common()[0][1] >= d: #if no need to cut
        return 0

    counter = [(-v, k) for k, v in Counter(a).items()]

    counter1 = [(k, v) for k, v in Counter(a).items()]
    counter1.sort()
    counter.sort()
    if debug:
        print("counter: ", counter)

    possible = set(a)
    n = len(possible)
    aha = list(possible)
    for i in range(n):
        for j in range(i+1, n):
            possible.add(gcd(aha[i], aha[j]))
    if debug:
        print("Possible Targets are: ", possible)
    mini = float('inf')
    for num in possible:
        served = 0
    # for i, (cnt, num) in enumerate(counter):
    #     cnt = -1 * cnt
    #     #check 
    #     served = cnt 
    #     if debug:
    #         print("i=%d, cnt=%d num=%d "%(i,cnt,num))
        for (cnt1, num1) in counter:
            served += num1 // num * abs(cnt1) #一开始abs没加 WA
            if served >= d: #ok with num pieces
                mini = min(mini, getMinCount(num, counter1, d))
                break
    return mini

def solve_small(n, d, a):
    global debug, test
    if n == 1:
        return d-1
    if n == 2 and d == 3:
        if a[0]==a[1]:
            return 2
        if a[0]%a[1] == 0 or a[1]%a[0] == 0:
            return 1
        else:
            return 2
    
    #n >= d only integer accepted
    
    if Counter(a).most_common()[0][1] >= d: #if no need to cut
        return 0

    counter = [(-v, k) for k, v in Counter(a).items()]

    counter1 = [(k, v) for k, v in Counter(a).items()]
    counter1.sort()
    counter.sort()
    if debug:
        print("counter: ", counter)
    mini = float('inf')
    for i, (cnt, num) in enumerate(counter):
        cnt = -1 * cnt
        #check 
        served = cnt 
        if debug:
            print("i=%d, cnt=%d num=%d "%(i,cnt,num))
        for (cnt1, num1) in counter:
            if num1 == num:
                continue
            served += num1 // num * abs(cnt1) #一开始abs没加 WA
            if served >= d: #ok with num pieces
                mini = min(mini, getMinCount(num, counter1, d))
                break
    return mini


T = int(input())
debug = False
test = True
for it in range(T):
    n, d = map(int, input().split())
    a = list(map(int, input().split()))
    ans = solve_large(n, d, a)
    print("Case #%d: %d"%(it+1, ans))