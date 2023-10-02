# /**
#  *     author: brownfox2k6
#  *    created: 16/08/2023 15:10:39 Hanoi, Vietnam
# **/
 
from math import comb
 
n = int(input())
print(comb(n, 5) + comb(n, 6) + comb(n, 7))