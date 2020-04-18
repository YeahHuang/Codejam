from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
import sys

"""
9min读题
小的 能问475个
大的 能问150个

[1,595]

小的： 问了4个能推出另一个 

大的： 按照概率算？ 不知道 

119 + 

一共120个
A*24 B*24 C*23 D*24 E*24

那么我其实只需要check C开头的全排列了



"""
T, f  =  map(int, input().split())
debug = True
out = open('hyh.txt','w')
for it in range(T):
    cnt = [[0]*5 for i in range(5)] #cnt [idx][A..E]
    for i in range(118):
        sett = set(['A','B','C','D','E'])
        for j in range(4):
            print(i*5+1+j)
            sys.stdout.flush()
            c = input()[0]
            cnt[j][ord(c)-ord('A')] += 1
            sett.remove(c)
        cnt[4][ord(list(sett)[0]) - ord('A')] += 1


    unknown =[[] for _ in range(5)]
    certain = [False] * 5
    for j in range(5):
        for i in range(5):
            if cnt[j][i] == 23:
                unknown[j].append(i)
            elif cnt[j][i] == 22:
                certain[j] = True
                break

    cn = 3
    ans = ['.' for _ in range(5)]
    for j in range(5):
        if cn==0:
            break
        if certain[j]==False:
            cn -= 1
            if True:
                print(118*5+1+j)
                sys.stdout.flush()
                c = input()[0]
                tmp = ord(c)-ord('A')
                cnt[j][tmp] += 1
                if tmp == unknown[j][0]:
                    ans[j] = chr(ord('A')+unknown[j][1])
                else:
                    ans[j] = chr(ord('A')+unknown[j][0])
            for k in range(5):
                if certain[k]==False and (unknown[k][0] == ord(c)-ord('A') or unknown[k][1] == ord(c)-ord('A')):
                    if unknown[k][0] == ord(c)-ord('A'):
                        cnt[k][unknown[k][1]] += 1
                    else:
                        cnt[k][unknown[k][0]] += 1
                    certain[k] = True
            certain[j] = True
    
    """
    for j in range(5):
        for i in range(5):
            if cn==0:
                break
            if cnt[j][i] == 23:
                print(118*5+1+j)
                sys.stdout.flush()
                c = input()[0]
                cnt[j][ord(c)-ord('A')] += 1
                cn -= 1
                break
    """

    if cn:
        for i in range(cn):
            print(1)
            sys.stdout.flush()
            c = input()[0]

    
    for j in range(5):
        com = []
        for i in range(5):
            if cnt[j][i] == 22:
                ans[j] = chr(ord('A') + i)
                break
            elif cnt[j][i] == 23:
                com.append(i)
        if len(com) == 1:
            ans[j] = chr(ord('A') + com[0])

    
    sett = set(['A','B','C','D','E'])
    wanted = -1
    for i in range(5):
        if ans[i]=='.':
            wanted = i
        else:
            sett.remove(ans[i])
    if wanted != -1:
        ans[wanted] = list(sett)[0]

    print("".join(ans))
    sys.stdout.flush()
    c = input()[0]
    if c == 'N':
        break