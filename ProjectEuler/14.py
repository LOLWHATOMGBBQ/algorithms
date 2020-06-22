# Longest Collatz sequence
tenm = 10000000
nums = [0 for i in range(tenm)]
nums[1] = 1

def next_num(n):
    if n & 1:
        return 3*n+1
    else:
        return n//2
def collatz(n):
    if n < tenm:
        if nums[n]:
            return nums[n]
        else:
            nums[n] = 1+collatz(next_num(n))
            return nums[n]
    else:
        return 1+collatz(next_num(n))


best = 0
bi = 0
for i in range(1, 1000001):
    cur = collatz(i)
    if best < cur:
        best = cur
        bi = i
print(bi)

