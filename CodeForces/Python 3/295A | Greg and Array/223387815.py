# /**
#  *     author: brownfox2k6
#  *    created: 15/09/2023 00:04:32 Hanoi, Vietnam
# **/
 
import sys
input = sys.stdin.readline
print = sys.stdout.write
 
readln = lambda: [*map(int, input().split())]
 
class operation:
    def __init__(self, l, r, d):
        self.l = l - 1
        self.r = r - 1
        self.d = d
 
class query:
    def __init__(self, x, y):
        self.x = x - 1
        self.y = y - 1
 
 
n, m, k = readln()
a = readln()
op = [operation(*readln()) for _ in range(m)]
qu = [query(*readln()) for _ in range(k)]
 
b = [0] * (m+1)
for q in qu:
    b[q.x] += 1
    b[q.y + 1] -= 1
for i in range(1, m+1):
    b[i] += b[i-1]
 
c = [0] * (n+1)
for i, o in enumerate(op):
    y = b[i] * o.d
    c[o.l] += y
    c[o.r + 1] -= y
for i in range(1, n+1):
    c[i] += c[i-1]
 
print(' '.join(map(str, map(lambda i: a[i]+c[i], range(n)))))