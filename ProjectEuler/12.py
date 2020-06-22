# Highly divisible triangular number
import operator
from functools import reduce

num_div = 500

def gcd(a,b):
  while b:
    a,b = b, a%b
  return a
def lca(a, b):
    return a*b//gcd(a,b)

N = 10000000
def num_facts(num):
    count = 0
    while not num%2:
        num //= 2
        count += 1
    divs = count + 1

    i = 3
    while i <= num:
        count = 0
        while not num%i:
            count += 1
            num //= i
        divs *= count + 1

        i += 2
    return divs
print("start")

n = 1
v = 1
while num_facts(v) <= 500:
    n += 1
    v += n
print(v)



#N = 10000000
#num_fact = [1 for i in range(N)]
#for i in range(2, N):
#    new_fact = num_fact[i] + 1
#    for j in range(i+i, N, i):
#        num_fact[j] += new_fact - num_fact[gcd(i, j)]
#    num_fact[i] += 1
#
#best = 0
#best_idx = 0
## formula is N*(N+1)/2
#for i in range(1, N, 2):
#    idx = (i+1)//2
#    cur = num_fact[i] + num_fact[idx] - num_fact[gcd(i, idx)]
#    if cur > best:
#        best = cur
#        best_idx = i
#
#print(f"{best}, {best_idx}")



#cur = 1
#for i in range(1, 501):
#    cur = lca(cur, i)
#print(cur)

