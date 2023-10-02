# /**
#  *     author: brownfox2k6
#  *    created: 25/09/2023 21:48:22 Hanoi, Vietnam
# **/
 
def solve():
    n = int(input())
    a = [[] for _ in range(n)]
    s = set()
 
    for i in range(n):
        x = [*map(int, input().split())][1:]
        s.update(x)
        a[i] = [*set(x)]
 
    ans = 0
 
    for v in s:
        cur = set()
 
        for i in range(n):
            ok = 0
            for x in a[i]:
                if x == v:
                    ok = 1
            if not ok:
                cur.update(a[i])
 
        ans = max(ans, len(cur))
 
    print(ans)
 
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()