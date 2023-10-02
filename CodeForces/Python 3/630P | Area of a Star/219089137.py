# /**
#  *     author: brownfox2k6
#  *    created: 16/08/2023 16:36:45 Hanoi, Vietnam
# **/
 
from math import tan, pi
 
n, r = map(int, input().split())
 
stri = (r**2) / (2 * (1/tan(pi/n) + 1/tan(pi/(2*n))))
print(2*n*stri)