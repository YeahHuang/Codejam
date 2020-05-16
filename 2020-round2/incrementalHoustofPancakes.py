from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
import random
import sys

global debug, test

def solve():
    global debug, test
"""
l, r 
ith order i 
from most pancakes remaining 一样的话左边 

output n(顾客数), l, r 


"""
MAX_ANS = 25*int(1e8)
def insertL(nums, target):
    l, r = 0, len(nums)-1
    while l<=r:
        mid = (l+r)//2
        if nums[mid] <= target:
            l = mid + 1
        else:
            r = mid - 1
    return r

def find(start, summ):
    l, r = 1, MAX_ANS
    while l <= r:
        mid = (l + r ) // 2
        if mid * (start + start + mid - 1) // 2 <= summ:
            l = mid + 1
        else:
            r = mid - 1
    return r


def find2(start, summ):
    l, r = 1, MAX_ANS
    while l <= r:
        mid = (l + r ) // 2
        if mid * (start + start + 2*mid - 2) // 2 <= summ:
            l = mid + 1
        else:
            r = mid - 1
    return r

def summ(start, n): # gap = 2
    return n * (start + start + 2 * n - 2) // 2

def solve_small(l, r):
    for i in range(1, int(1e9)):
        if max(l, r) < i:
            ans = i-1
            break
        if l >= r:
            l -= i
        else:
            r -= i
    return ans, l, r

def solve_large(l, r):
    swap_flag = False
    # if l < r:
    #     swap_flag = True
    #     l, r = r, l
    # else:
    #     swap_flag = False
    nexti = find(1, abs(l-r)) + 1
    if debug:
        #solve_small(l, r)
        print("First nexti=%d summ=%d"%(nexti, (nexti-1) * (1 + nexti-1) // 2 ))
    if l >= r:
        l -= (nexti-1) * nexti // 2
        res = find2(nexti, l)
        if res > PROX_GAP:
            l -= summ(nexti, res - PROX_GAP)
            r -= summ(nexti+1, res - PROX_GAP)
            nexti += 2 * (res-PROX_GAP) 
    else:
        r -= (nexti-1) * nexti // 2
        res = find2(nexti, r)
        if res > PROX_GAP:
            if l == r:
                l -= summ(nexti, res - PROX_GAP)
                r -= summ(nexti+1, res - PROX_GAP)
                nexti += 2 * (res-PROX_GAP) 
            else:
                r -= summ(nexti, res - PROX_GAP)
                l -= summ(nexti+1, res - PROX_GAP)
                nexti += 2 * (res-PROX_GAP) 

    if debug:
        print("res=%d nexti=%d l=%d r =%d "%(res, nexti, l,r))
    for i in range(nexti, MAX_ANS):
        if max(l, r) < i:
            ans = i-1
            break
        if l >= r:
            l -= i
            if debug:
                print("i=%d get l, %d %d gap=%d"%(i,l, r, l-r))
        elif l < r:
            r -= i
            if debug:
                print("i=%d get r, %d %d gap=%d"%(i,l, r, l-r))
        # else: #l == r:
        #     if swap_flag:
        #         r -= i
        #     else:
        #         l -= i

    if swap_flag:
        l, r = r,l
    return ans,l,r



debug = False
test = False
if test:
    T = 1
else:
    T = int(input())
PROX_GAP = 5
for it in range(T):
    if test:
        
        l,r = 94, 97
        for l in range(1, 101):
            for r in range(1, 101):
                a1, l1, r1 = solve_small(l, r)
                a2, l2, r2 = solve_large(l, r)
                if not (a1==a2 and l2==l1 and r1==r2):
                    print("ERROR when l=%d r=%d should be(%d %d %d) but get (%d %d %d)"%(l,r,a1,l1,r1, a2,l2,r2))

    else:
        l, r = map(int, input().split())
    ans, l, r = solve_large(l, r)
    print("Case #%d: %d %d %d"%(it+1, ans,l, r))
