# /**
#  *     author: brownfox2k6
#  *    created: 31/08/2023 10:49:46 Hanoi, Vietnam
# **/
 
def solve():
    n, a, _ = map(int, input().split())
    s = input()
    if a + s.count('+') < n:
        return "NO"
    if a == n:
        return "YES"
    for c in s:
        if c == '+':
            a += 1
        else:
            a -= 1
        if a == n:
            return "YES"
    return "MAYBE"
 
 
_T = 1
_T = int(input())
for _ in range(_T):
    print(solve())