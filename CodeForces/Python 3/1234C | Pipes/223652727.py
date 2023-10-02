# /**
#  *     author: brownfox2k6
#  *    created: 17/09/2023 00:54:02 Hanoi, Vietnam
# **/
 
def solve():
    n = int(input())
    s = [input() for _ in range(2)]
 
    currow = 0
    for curcol in range(n):
        if s[currow][curcol] >= '3':
            if s[currow ^ 1][curcol] < '3':
                return print("NO")
            currow ^= 1
 
    if currow == 1 and curcol == n-1:
        print("YES")
    else:
        print("NO")
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()