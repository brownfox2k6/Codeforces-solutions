import sys
input = sys.stdin.readline
print = sys.stdout.write
 
def solve():
    n = int(input())
    s = input()
 
    c = p = 0
    for i in range(n//2):
        if s[i] != s[n-i-1]:
            c += 1
        if s[i] == s[n-i-1]:
            p += 1
    
    ans = '1' if c == 0 else '0'
    
    for i in range(1, n+1):
        if c > i or i-c > 2*p + (n & 1):
            ans += '0'
        elif (i - c) & 1:
            ans += str(n & 1)
        else:
            ans += '1'
    
    print(ans + '\n')
 
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()