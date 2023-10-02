# /**
#  *     author: brownfox2k6
#  *    created: 26/09/2023 21:35:50 Hanoi, Vietnam
# **/
 
def solve():
    n, k = map(int, input().split())
    print("YES" if k in [*map(int, input().split())] else "NO")
 
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()