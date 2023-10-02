# /**
#  *     author: brownfox2k6
#  *    created: 22/09/2023 21:01:48 Hanoi, Vietnam
# **/
 
n, k = map(int, input().split())
s = input()
 
cur = ""
ans = "z" * 5001
for i in range(n):
    cur += s[i]
    ans = min(ans, cur*((5000+i) // (i+1)))
print(ans[:k])