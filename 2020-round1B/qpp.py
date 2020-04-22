from bisect import bisect_left, bisect_right, insort_left,  insort_right
from string import ascii_lowercase
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from itertools import product

T = int(input())

for it in range(T):
    l, r = map(int, input().split())
    p = list(map(int, input().split()))
    ans = 0
    print("Case #%d: %d"%(it+1, ans))


out = open('hyh.txt','w') print("", file=out)
#!/usr/bin/python3 main文件需要

from string import ascii_lowercase
from bisect import bisect_left, bisect_right, insort_left
from collections import defaultdict, Counter, deque, nemedtuple, OrderedDict
from operator import add
from heapq import heapify, heappop
from re import split, sub

def insertR(nums, target):
    l,r = 0, len(nums)-1
    while l<=r:  
        mid = (l+r)//2
        if nums[mid] < target:
            l = mid + 1
        else:
            r = mid - 1
    return l

def insertL(nums, target):
    l, r = 0, len(nums)-1
    while l<=r:
        mid = (l+r)//2
        if nums[mid] <= target:
            l = mid + 1
        else:
            r = mid - 1
    return r

class DSU: #Disjoint Set Union 就是常见的染色问题
    def __init__(self,n):
        self.p = {}
        for i in range(1,n+1):
            self.p[i] = i

    def find(self, x):
        stack = []
        while self.p[x] != x:
            stack.append(x)
            x = self.p[x]
        for xx in stack:
            self.p[xx] = x
        '''
        if self.p[x] != x: 会MLE
            self.p[x] = self.find(self.p[x])
        '''
        return x

    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if y == py:
            self.p[px] = self.p[py]
        else:
            self.p[py] = self.p[px]
        return px!=py



快排的partition

def partition(l, r):
    if l>=r:
        return
    pivot = a[l]
    i, j = l+1, r
    while True:
        while i<j and a[i]<pivot:
            i+=1
        while i<=j and a[j]>=pivot:
            j-=1
        if i>=j:
            break
        a[i], a[j] = a[j], a[i]
    a[l], a[j] = a[j], a[l]
    return j


nums = [1,3,5,7,9]
print("ori:",nums)
print("insertL, 0,1,2,3,4,5,6,7,8,9,10:", [insertL(nums,i) for i in range(11)])
print("insertR, 0,1,2,3,4,5,6,7,8,9,10:", [insertR(nums,i) for i in range(11)])


bisect.insort_left(self.records, (timestamp, id))
l = bisect.bisect_left(self.records, (s, 0))
r = bisect.bisect_right(self.records, (e, float('inf')))
return [id for (_, id) in self.records[l:r]]

n =  sum(map(lambda x: int(x)**2, list(str(n)))) 

map(''.join, itertools.product(list1, list2))代替自己写的zip会快 
>>> l1 = ['a','b','c']
>>> l2 = ['ee','ff']
>>> list(map(''.join, itertools.product(l1,l2)))
['aee', 'aff', 'bee', 'bff', 'cee', 'cff']

tuple(map(operator.add,a, b))
dict的参数转换很酷： idx = {‘Year’:5, ‘’Month’:8…}[gra]

collections.defaultdict(set)
Stone = collections.namedtuple('Stone',['s','e','l','maxs'])

chr(i) ord('A')

filter(lambda log: log[log.find(" ") + 1].isalpha(), logs)

de = collections.deque([1,2,3])
de.append(4) #默认右边，appendleft
de.pop() #默认右边，popleft
de.count(x) #输出和x相等的数量
de.remove(x) #remove第一个
de.extend([4,5,6]) #extendleft,  加iteratable
de.ratate(n=1)  n可以为- 就是反方向left转了 
clear


maxlen属性 deque([iterable[,maxlen]])


Binary Index Tree:
1. x & (-x) 就是last set bit in a number x
    e.g. 当x=10(decimal) = 1010(b)  x&-x = (10)1(0)&(01)1(0) = 2(decimal)
2. BIT[i] = sum(num[i-(1<<r)+1]..num[i]) r就是上面说的last set bit 
    所以如果i是奇数 就只有它本身; 如果i是2的poweder 那就直接是sum(num[0]..num[i])
3. 需满足可逆性 比如 * / + - 但是gcd这样不可逆的就么的办法了

class BIT:
    def __init__(self, n, nums):
        self.BIT = [0]*n+1
        for i,num in enumerate(nums):
            self.update(i+1, num)

    def update(idx, val):
        while idx <= n: 
            self.BIT[idx] += val
            idx += idx & -idx

    def query(idx):
        sum = 0
        while idx>0:
            sum += self.BIT[idx]
            idx -= idx & -idx
        return sum

d = {"banana":3, 'apple':4, 'pear':1, 'orange':2};

>>> # dictionary sorted by length of the key string
>>> OrderedDict(sorted(d.items(), key=lambda t: len(t[0])))
OrderedDict([('pear', 1), ('apple', 4), ('orange', 2), ('banana', 3)])

paragraph = re.sub("[!?',;.]"," ", paragraph.lower())
re.sub(r'\sAND\s', ' & ', 'Baked Beans And Spam', flags=re.IGNORECASE)
#'Baked Beans & Spam'
re.split('\w+', 'Words, words, words.')
['Words', 'words', 'words', '']

words = re.findall(r'\w+',p.lower())

result = string.ascii_lowercase 
    
# Printing the value  
print(result)

1. 注意题目是否读错 一定要静下心来 无论题目多么复杂
2. n =  sum(map(lambda x: int(x)**2, list(str(n)))) 
3.map(''.join, itertools.product(list1, list2))
4. TreeNode之类的指针没有办法一次TreeNode(10) 多次赋值.left .right的
5. str不支持直接替换的 如果要修改部分的s 可以写成 s = s[:17]+’00’;  
dict的参数转换很酷： idx = {‘Year’:5, ‘’Month’:8…}[gra]
6. unichr(258)
7. WA1 set1=set1.union(set2) 才会真的改变set1；
8. math.factorial 

手写快排 + insort_left, right 
bisect.insort_left(list, int)
bisect_insort_right()


heapq.heapify(sticks)
heapq.heappop(sticks)
heapq.heappush(sticks, p1+p2)
