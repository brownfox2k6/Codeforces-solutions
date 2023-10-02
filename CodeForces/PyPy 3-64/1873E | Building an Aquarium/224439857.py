# /**
#  *     author: brownfox2k6
#  *    created: 21/09/2023 22:49:33 Hanoi, Vietnam
# **/
 
import sys, bisect
input = sys.stdin.readline
# print = sys.stdout.write
 
def solve():
    n, x = map(int, input().split())
    a = sorted(map(int, input().split()))
 
    p = [0]
    for i in range(n):
        p.append(p[i] + a[i])
 
    low = a[0]
    high = 1 << 64
    ans = 1 << 64
    while high - low > 1:
        mid = (low + high) >> 1
        ind = bisect.bisect_right(a, mid)
        total = mid*ind - p[ind]
        if total <= x:
            low = mid
        else:
            high = mid
 
    print(low)
 
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()