# /**
#  *     author: brownfox2k6
#  *    created: 27/08/2023 14:46:26 Hanoi, Vietnam
# **/
 
from math import comb
 
boys, girls, n = map(int, input().split())
ans = 0
for b in range(4, n):
    ans += comb(boys, b) * comb(girls, n-b)
print(ans)