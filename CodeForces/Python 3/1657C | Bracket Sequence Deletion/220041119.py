# /**
#  *     author: brownfox2k6
#  *    created: 23/08/2023 21:08:04 Hanoi, Vietnam
# **/
 
import sys
input = sys.stdin.readline
print = sys.stdout.write
 
def solve():
    n = int(input())
    s = input()
    cnt = 0
    l = 0
    while l < n-1:
        if s[l] == '(' or s[l:l+2] == "))":
            l += 2
        else:
            r = l+1
            while r < n and s[r] == '(':
                r += 1
            if r == n:
                break
            l = r+1
        cnt += 1
    return f"{cnt} {n-l}"
 
print('\n'.join(solve() for _ in range(int(input()))))