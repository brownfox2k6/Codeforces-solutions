# /**
#  *     author: brownfox2k6
#  *    created: 29/09/2023 01:24:19 Hanoi, Vietnam
# **/
 
def solve():
    n = int(input())
    a = [*range(1, n-2), 1<<29, 1<<30]
    xor = 0
    for x in a:
        xor ^= x
    print(*a, xor)
 
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()