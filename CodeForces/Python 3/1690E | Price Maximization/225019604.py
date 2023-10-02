# brownfox2k6
# 9.24 am
 
readln = lambda : [*map(int, input().split())]
 
for _ in range(int(input())):
    n, k = readln()
    a = readln()
 
    ans = 0
    for i in range(n):
        ans += a[i] // k
        a[i] %= k
 
    a.sort(reverse=True)
    l = 0
    r = n-1
    while l < r:
        if a[l] + a[r] >= k:
            ans += 1
            l += 1
        r -= 1
 
    print(ans)