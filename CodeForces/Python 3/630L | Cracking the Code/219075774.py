# /**
#  *     author: brownfox2k6
#  *    created: 16/08/2023 14:59:18 Hanoi, Vietnam
# **/
 
n = input()
n = n[0] + n[2] + n[4] + n[3] + n[1]
n = int(n)
 
ans = 1
for _ in range(5):
    ans = ans*n % 100000
 
print("{:0>5}".format(ans))