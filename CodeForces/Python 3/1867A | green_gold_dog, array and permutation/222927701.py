# /**
#  *     author: brownfox2k6
#  *    created: 11/09/2023 21:50:01 Hanoi, Vietnam
# **/
 
def solve():
    n = int(input())
    a = [*map(list, enumerate(map(int, input().split())))]
    a.sort(key=lambda x:x[1])
    for i in range(n):
        a[i][1] = n-i
    a.sort()
    for x in a:
        print(x[1])
 
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()