# /**
#  *     author: brownfox2k6
#  *    created: 22/09/2023 20:47:11 Hanoi, Vietnam
# **/
 
from collections import Counter
 
n, k = map(int, input().split())
a = Counter(input().split())
 
def f(x):
    ans = []
    for i in a:
        can = min(k-len(ans), a[i]//x)
        ans.extend([i] * can)
    return ans
 
low = 1
high = n
while high - low > 1:
    mid = (low + high) >> 1
    if len(f(mid)) == k:
        low = mid
    else:
        high = mid
 
a = f(low)
if len(a) == k:
    print(' '.join(a))
else:
    print(' '.join(f(high)))