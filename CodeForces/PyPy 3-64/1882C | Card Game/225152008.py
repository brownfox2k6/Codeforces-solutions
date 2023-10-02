# /**
#  *     author: brownfox2k6
#  *    created: 25/09/2023 21:48:22 Hanoi, Vietnam
# **/
 
def solve():
    n = int(input())
    a = [*map(int, input().split())]
    b = [0] * (n+1)
    for i in range(n-1, -1, -1):
        b[i] = b[i+1] + max(0, a[i])
    print(max(0, *[b[i+1] + (0 if i & 1 else a[i]) for i in range(n)]))
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()