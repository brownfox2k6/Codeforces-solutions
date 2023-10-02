# /**
#  *     author: brownfox2k6
#  *    created: 16/08/2023 15:24:32 Hanoi, Vietnam
# **/
 
n = int(input())
def ninrange(x, l=1, r=n):
    """
    Count how many numbers in [l, r] divisible by x
    """
    if (l % x):
        l += x - l % x
    r -= r % x
    return (r - l) // x + 1
 
 
print(
    n
    - ninrange(2)
    - ninrange(3)
    - ninrange(5)
    - ninrange(7)
    + ninrange(2*3)
    + ninrange(2*5)
    + ninrange(2*7)
    + ninrange(3*5)
    + ninrange(3*7)
    + ninrange(5*7)
    - ninrange(2*3*5)
    - ninrange(2*3*7)
    - ninrange(2*5*7)
    - ninrange(3*5*7)
    + ninrange(2*3*5*7)
)