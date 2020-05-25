MOD = 1000000007
T = int(input())

for t in range(T):
    N = int(input())
    if N%3 == 0:
        ans = pow(3, N//3, MOD)
    elif N%3 == 1:
        if N == 1:
            ans = 1
        else:
            ans = pow(3, (N-4)//3, MOD)*4%MOD
    else:
        ans = pow(3, (N-2)//3, MOD)*2%MOD
    print(ans)

