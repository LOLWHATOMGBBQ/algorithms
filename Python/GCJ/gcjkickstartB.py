import sys

sys.stdin = open("B-large-practice.in", "r")
sys.stdout = open("out.out", "w")
raw_input = sys.stdin.readline

T = int(raw_input())
for test in xrange(1, T+1):
    N, K = map(int, raw_input().split())
    A = map(lambda x: int(x)^K, raw_input().split())
    B = map(int, raw_input().split())
    xors = {}
    for i in xrange(N):
        for j in xrange(N):
            val = A[i]^B[j]
            if val in xors:
                xors[val] += 1
            else:
                xors[val] = 1
    C = map(int, raw_input().split())
    D = map(int, raw_input().split())
    tot = 0
    for i in xrange(N):
        for j in xrange(N):
            val = C[i]^D[j]
            if val in xors:
                tot += xors[val]
    print "Case #%d: %d"%(test, tot)
