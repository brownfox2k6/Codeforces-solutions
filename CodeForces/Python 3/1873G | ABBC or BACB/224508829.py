# /**
#  *     author: brownfox2k6
#  *    created: 21/09/2023 22:49:33 Hanoi, Vietnam
# **/
 
def solve():
    s = [*map(len, input().split('B'))]
    print(sum(s) - min(s))
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()