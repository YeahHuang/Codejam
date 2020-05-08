"""
不要随意刷新页面
11:56-12:09 读完题 但是因为看不到output随意刷新了
然后写的comments都没了
就有点心态崩emmm 直接下楼了emmm

其实是可做的吧  但不知道为什么显示有bug
r = [1,5]
c [1,50]
一行/列有两个 那肯定 得 相反排列
冲突了 比如角落里 就直接impossible
0  empty
1  light(either way)
2  must horizontal -
3  must vertical |


0 - no light
4 - has light

然后枚举每一个1 是 2 or 3
直到符合了 就pass

r,c
output possible/impossible
是possible要输出的
"""