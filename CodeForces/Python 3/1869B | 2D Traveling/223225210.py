# /**
#  *     author: brownfox2k6
#  *    created: 13/09/2023 20:55:52 Hanoi, Vietnam
# **/
 
import sys
input = sys.stdin.readline
print = sys.stdout.write
 
def dist(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])
 
def solve():
    n, k, src, dst = map(int, input().split())
    src -= 1
    dst -= 1
    p = [tuple(map(int, input().split())) for _ in range(n)]
    
    minsrc = float('inf')
    mindst = float('inf')
    for i in range(k):
        minsrc = min(minsrc, dist(p[src], p[i]))
        mindst = min(mindst, dist(p[dst], p[i]))
    
    fly = dist(p[src], p[dst])
    nofly = minsrc + mindst
    return min(fly, nofly)
 
print('\n'.join(map(str, (solve() for _ in range(int(input()))))))