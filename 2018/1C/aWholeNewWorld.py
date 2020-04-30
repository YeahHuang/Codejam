from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product
"""
 N and L: the number of Vincent's words, and the length of each word. 
 n more lines  每行一个长度为L的单词
 
 小： l  = 2 n<=26*26
 大： l <= 10 n <= 2000
 
 5:06

 5:29 - 5:32 pass 小的
 
 小的： 两重循环 每一个set 一下 然后直接暴力枚举是否已经存在 
 大的 同样可以哈希的 排列组合嘛 
 甚至可以用trie 只要任意一个结点 可以选择另一个就行 


每一层 set。 

每到一层 判断children数量是否等于set[l]


= 暴力枚举
不等于 把不存在的找出来 然后 OK 

建树的时候直接判断也OK 

6:09 大的RE了
6:24 AC!
"""
global debug

def solve_small(n, l, w):
    if l == 1:
        return "-"
    ss = set(w)
    s0 = set([s[0] for s in w])
    s1 = set([s[1] for s in w])
    for c0 in s0:
        for c1 in s1:
            if c0 + c1 not in ss:
                return c0+c1
    return "-"

class TrieNode:
    def __init__(self):
        self.children = defaultdict(TrieNode)
        self.end = ""

class Trie:
    def __init__(self, ss, l):
        self.root = TrieNode() 
        self.ss = ss
        self.l = l 
        self.found = False
        self.newWord = ""
        self.debug = False

    def findNew(self):
        if self.debug:
            print("ss", self.ss)
        for c in self.root.children:
            self.dfs(0, self.root.children.get(c))
            if self.found:
                return self.newWord
        return '-'

    def dfs(self, step, cur):
        if step == l-1: #reaches leaf node 
            if self.debug:
                print("Reaching: ", cur.end)
            return
        if self.debug:
            print("dfs step=%d,  has %d children, len(self.ss[step+1]=%d"%(step,len(cur.children),len(self.ss[step+1])) )
        if len(cur.children) < len(self.ss[step+1]): #found!!!
            for c in self.ss[step+1]:
                if cur.children.get(c) is None:
                    not_exist = c
                    break
            tmp = cur
            if self.debug:
                print("Start!")
            for i in range(step, self.l):
                for c in tmp.children:
                    tmp = tmp.children.get(c)
                    if self.debug:
                        print("i=%d tmp.end=%s"%(i, tmp.end))
                    break
            self.found = True
            
            self.newWord = tmp.end[:step+1] + not_exist + tmp.end[step+2:]
            return
        else: #full nodes
            for c in self.ss[step+1]:
                if self.debug:
                    print()
                self.dfs(step+1, cur.children.get(c))
                if self.found:
                    return

    def insert(self, word):
        cur = self.root
        for c in word:
            cur = cur.children[c]
        cur.end = word

    def search(self, word):
        cur = self.root
        is_exist = True
        for c in word:
            cur = cur.children.get(c) #这里为了判定是否为空 由直接新建 -> .get 函数 注意一下
            if cur is None:
                is_exist = False
                break
        return is_exist and cur.end

    def startsWith(self, prefix):
        cur = self.root
        is_prefix = True
        for c in prefix:
            cur = cur.children.get(c) #这里为了判定是否为空 由直接新建 -> .get 函数 注意一下
            if cur is None:
                is_prefix = False
                break
        return is_prefix

def solve_large(n, l, w):
    if l == 1:
        return "-"
    ss = [set() for _ in range(l)]
    for i in range(l):
        ss[i] = set([s[i] for s in w])
    trie = Trie(ss, l)
    for s in w:
        trie.insert(s)
    return trie.findNew()



T = int(input())
debug = True
test = False
for it in range(T):
    if test:
        n, l = 2000, 10

    n, l = map(int, input().split())
    w = [input() for _ in range(n)]
    if l <= 2:
        ans = solve_small(n, l, w)
    else:
        ans = solve_large(n, l, w)
    print("Case #%d: %s"%(it+1, ans))
