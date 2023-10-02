# /**
#  *     author: brownfox2k6
#  *    created: 16/08/2023 15:14:32 Hanoi, Vietnam
# **/
 
a, b, c = map(int, input().split())
 
x = (b**2 - 4*a*c) ** 0.5
roots = [(-b+x)/(2*a), (-b-x)/(2*a)]
roots.sort(reverse=True)
print(*roots, sep='\n')