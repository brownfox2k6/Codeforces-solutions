# /**
#  *     author: brownfox2k6
#  *    created: 04/09/2023 14:46:27 Hanoi, Vietnam
# **/
 
inp = [[*map(int, x.split())] for x in open(0)]
n = inp[0]
x = {i: j for i, j in zip(inp[1], inp[2])}
m = inp[3]
y = {i: j for i, j in zip(inp[4], inp[5])}
 
for num in y:
    if num not in x or x[num] < y[num]:
        exit(print(0))
 
oknums = set()
for num in x:
    if num not in y or x[num] > y[num]:
        oknums.add(num)
for num in y:
    if num in x and x[num] > y[num]:
        oknums.add(num)
 
def bpow(n, k, m=998244353):
    ans = 1
    while k:
        if k & 1:
            ans = (ans * n) % m
        n = (n * n) % m
        k >>= 1
    return ans
 
print(bpow(2, len(oknums)))