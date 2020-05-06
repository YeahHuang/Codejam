from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
import random
import sys
"""
11:57 -  13:01 pass 

n(number of groups) p(number of pieces of chocolate per pack)
g1..gn 每组多少人

Case #x: y（the number of groups that will receive only fresh chocolate if you bring them in in an order that maximizes that number）

n: [1,100]
gi [1,100]

小 p [2,3]
大 p [2,4]
"""


global debug, test

def solve():
    global debug, test

T = int(input())
debug = False
test = True
for it in range(T):
    n, p = map(int, input().split())
    g = list(map(lambda x: int(x)%p, input().split()))
    cnt = Counter(g)
    for i in range(p):
        if i not in cnt.keys():
            cnt[i] = 0

    ans = 0
    ans += cnt[0]
    cnt[0] = 0 #一开始这个没加 WA 2次
    if debug:
        print("step0 add %d"%ans)
    for i in range(1, p):
        if i == p-i:
            ans += cnt[i] // 2
            cnt[i] -= cnt[i] // 2 * 2 
        else:
            pair = min(cnt[i], cnt[p-i])
            ans, cnt[i], cnt[p-i] = ans + pair, cnt[i]- pair, cnt[p-i]-pair
    if debug:
        print("2 combine to 1ans=%d"%ans)
    if p == 3:
        #3 combines to 1
        ans += cnt[1] // 3 + cnt[2] // 3
        cnt[1], cnt[2] = cnt[1]%3, cnt[2]%3
    elif p == 4:
        #3 combines to 1  1 1 2 or 3 3 2 
        if cnt[2] > 0:
            if cnt[1] > 0:
                pair = min(cnt[2], cnt[1]//2)
                ans, cnt[1], cnt[2] = ans + pair, cnt[1] - pair*2, cnt[2] - pair
            else: 
                pair = min(cnt[2], cnt[3]//2)
                ans, cnt[3], cnt[2] = ans + pair, cnt[3] - pair*2, cnt[2] - pair

        #4 combines to 1 1 1 1 1 or 3 3 3 3 
        ans += cnt[1] // 4
        cnt[1] %= 4

        ans += cnt[3] // 4
        cnt[3] %= 4 
    if debug:
        print("2 combine ans = %d"%ans)
    if sum([v for k, v in cnt.items()]) > 0:
        ans += 1
    print("Case #%d: %d"%(it+1, ans))
