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

T = int(input())
debug = True
test = True
for it in range(T):
    l, r = map(int, input().split())
    p = list(map(int, input().split()))
    ans = 0
    print("Case #%d: %d"%(it+1, ans))
