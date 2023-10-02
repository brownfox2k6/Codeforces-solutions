# /**
#  *     author: brownfox2k6
#  *    created: 24/08/2023 21:37:29 Hanoi, Vietnam
# **/
 
import sys
import collections
input = sys.stdin.readline
print = sys.stdout.write
 
def solve():
    n = int(input())
    a = [*map(int, input().split())]
    if a[0] != n:
        return print("NO\n")
    a = collections.Counter(a)
    a = [(x, a[x]) for x in a.keys()]
    # print(a)
    for i in range(len(a)-1):
        diff = a[i][0] - a[i+1][0]
        if diff != a[-i-1][1]:
            # print(i)
            return print("NO\n")
 
    # print(a)
    print("YES\n")
    
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()