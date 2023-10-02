# /**
#  *     author: brownfox2k6
#  *    created: 26/09/2023 21:48:00 Hanoi, Vietnam
# **/
 
def solve():
    n, k, x = map(int, input().split())
    maxx = k * (n + (n-k+1)) // 2
    minn = k * (k + 1) // 2
    if minn <= x <= maxx:
        print("YES")
    else:
        print("NO")
 
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()