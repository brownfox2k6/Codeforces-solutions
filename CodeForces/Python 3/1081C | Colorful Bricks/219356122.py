# /**
#  *     author: brownfox2k6
#  *    created: 18/08/2023 00:35:26 Hanoi, Vietnam
# **/
 
from math import comb
 
def mul(a, b):
    return (a * b) % 998244353
 
def bpow(n, k):
    ans = 1
    while k:
        if k & 1:
            ans = mul(ans, n)
        n = mul(n, n)
        k >>= 1
    return ans
 
 
n, m, k = map(int, input().split())
print(mul(comb(n-1, k), mul(m, bpow(m-1, k))))