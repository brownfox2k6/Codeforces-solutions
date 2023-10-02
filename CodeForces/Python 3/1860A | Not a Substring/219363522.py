# /**
#  *     author: brownfox2k6
#  *    created: 18/08/2023 01:37:58 Hanoi, Vietnam
# **/
 
def solve():
    s = input()
    if s == '()':
        return print("NO")
    print("YES")
    s1 = '()' * len(s)
    s2 = '(' * len(s) + ')' * len(s)
    print(s2 if s in s1 else s1)
 
 
_T = 1
_T = int(input())
for _ in range(_T):
    solve()