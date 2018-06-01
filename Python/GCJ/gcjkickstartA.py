import sys
import bisect



sys.stdin = open("A-large-practice.in", "r")
raw_input = sys.stdin.readline
# k = sys.stdout
sys.stdout = open("out.out", "w")

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a


T = int(raw_input())
for test_case in xrange(1, T+1):
    print "Case #%d"%test_case
    raw_input()
    N_p, N_e, N_t = map(int, raw_input().split())
    
    base = map(int, raw_input().split())
    extra = map(int, raw_input().split())
    end = map(int, raw_input().split())
    den = {end[i]*extra[j]:j for j in xrange(N_e) for i in xrange(N_t)}
    Q = int(raw_input())
    for q in xrange(Q):
        top, bot = map(int, raw_input().split())
        for idx in xrange(N_e*N_p):
            key = extra[idx/N_p]*base[idx%N_p]
    
            ntop = bot*key
            if gcd(ntop, top) == top and ntop/top in den and idx/N_p != den[ntop/top]:
                print "Yes"
                break
        else:
            print "No"
