# /**
#  *     author: brownfox2k6
#  *    created: 16/08/2023 16:02:56 Hanoi, Vietnam
# **/
 
sq = lambda x : x**2
 
n = int(input())
 
print(sq(n) * sq(n-1) * sq(n-2) * sq(n-3) * sq(n-4) // 120)