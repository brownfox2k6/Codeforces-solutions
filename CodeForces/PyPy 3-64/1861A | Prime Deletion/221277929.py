# /**
#  *     author: brownfox2k6
#  *    created: 31/08/2023 21:36:54 Hanoi, Vietnam
# **/
 
p = list(map(str, [13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]))
 
def solve():
    s = input()
    for x in p:
        if s.index(x[0]) < s.index(x[1]):
            return print(x)
 
 
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()