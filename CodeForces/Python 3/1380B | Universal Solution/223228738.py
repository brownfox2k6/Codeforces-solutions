# /**
#  *     author: brownfox2k6
#  *    created: 13/09/2023 21:21:57 Hanoi, Vietnam
# **/
 
import sys
input = sys.stdin.readline
print = sys.stdout.write
 
def solve():
    r = s = p = 0
    i = input().strip()
    for c in i:
        if c == 'R':   r += 1
        elif c == 'S': s += 1
        else:          p += 1
    mx = max(r, s, p)
    if mx == r:   return 'P' * len(i)
    elif mx == s: return 'R' * len(i)
    else:         return 'S' * len(i)
 
 
print('\n'.join(solve() for _ in range(int(input()))))