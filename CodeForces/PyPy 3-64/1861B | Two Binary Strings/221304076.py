# /**
#  *     author: brownfox2k6
#  *    created: 31/08/2023 21:40:48 Hanoi, Vietnam
# **/
 
def ok(l1, r1, l2, r2, n):
    if (l2 - r1 == 1 or l1 - r2 == 1) and (r2 - l1 == n-1 or r1 - l2 == n-1):
        return True
    return False
 
def solve():
    a = input()
    b = input()
    for i in range(len(a)-1):
        if a[i] == b[i] == '0' and a[i+1] == b[i+1] == '1':
            return print("YES")
    print("NO")
 
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()