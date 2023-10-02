# /**
#  *     author: brownfox2k6
#  *    created: 22/08/2023 14:05:16 Hanoi, Vietnam
# **/
 
import sys
input = sys.stdin.readline
print = sys.stdout.write
 
# check if [l, r] in ast[i]
def check(asti, l, r):
    low = 0
    high = len(asti) - 1
    while low <= high:
        mid = (low + high) >> 1
        # If [l, r] completely inside asti[mid] -> ok
        if l >= asti[mid][0] and r <= asti[mid][1]:
            return True
        # If [l, r] partially inside asti[mid] -> not ok
        if asti[mid][0] <= l <= asti[mid][1] or asti[mid][0] <= r <= asti[mid][1]:
            return False
        # If [l, r] completely outside asti[mid]
        if l > asti[mid][1]:
            low = mid + 1
        else:
            high = mid - 1
    return False
 
 
def solve():
    n, m = map(int, input().split())
    ast = [[] for _ in range(n)]
    for i in range(n):
        s = input()
        for j in range(m):
            if s[j] == '*':
                if not ast[i]:
                    ast[i].append([j, j])
                elif ast[i][-1][0] == -1:
                    ast[i][-1] = [j, j]
                else:
                    ast[i][-1][1] += 1
            else:
                if ast[i] and ast[i][-1][0] != -1:
                    ast[i].append([-1, -1])
        if ast[i] and ast[i][-1][0] == -1:
            ast[i].pop()
 
    ans = 0
    for i in range(n):
        for j in range(m):
            for k in range(min(n-i, m-j, j+1)):
                if check(ast[i+k], j-k, j+k):
                    ans += 1
                else:
                    break
 
    return str(ans)
 
 
print('\n'.join(solve() for _ in range(int(input()))))