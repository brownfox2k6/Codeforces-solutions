# /**
#  *     author: brownfox2k6
#  *    created: 28/09/2023 12:28:23 Hanoi, Vietnam
# **/
 
n = int(input())
x = [*map(int, input().split())]
v = [*map(int, input().split())]
 
low, high = 0, 2e9
 
while high - low >= 1e-6:
    mid = (low + high) / 2
    lb = 0
    ub = 2e9
    for pos, vel in zip(x, v):
        lb = max(lb, pos - vel*mid)
        ub = min(ub, pos + vel*mid)
    if lb < ub or abs(lb - ub) < 1e-6:
        high = mid
    else:
        low = mid
 
print(high)