# /**
#  *     author: brownfox2k6
#  *    created: 24/08/2023 21:37:29 Hanoi, Vietnam
# **/
 
def solve():
    n, m = map(int, input().split())
    a = list(zip(*[input() for _ in range(n)]))
    a = [''.join(x) for x in a]
    state = 0
    for x in a:
        if state == 0 and 'v' in x:
            state = 1
        elif state == 1 and 'i' in x:
            state = 2
        elif state == 2 and 'k' in x:
            state = 3
        elif state == 3 and 'a' in x:
            state = 4
    print("YES" if state == 4 else "NO")
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()