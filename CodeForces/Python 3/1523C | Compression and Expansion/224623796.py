# /**
#  *     author: brownfox2k6
#  *    created: 22/09/2023 21:16:40 Hanoi, Vietnam
# **/    
 
def solve():
    n = int(input())
    stack = []
    for _ in range(n):
        x = int(input())
        if x == 1:
            stack.append(x)
        else:
            while x != stack[-1] + 1:
                stack.pop()
            stack[-1] = x
        print('.'.join(map(str, stack)))
 
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()