#code
for _ in range(int(input())):
    N, M = map(int, input().split())
    arr = list(map(int, input().split()))
    beg = -1
    end = 0
    cum = 0
    if arr[0] > M:
        print(1)
        continue
    best = 9999999
    while end < N:
        cum += arr[end]
        while cum > M:
            #print("%d %d %d %d"%(cum, beg, end, arr[beg+1]))
            best = min(best, end - beg)
            cum -= arr[beg+1]
            beg += 1
            
        end += 1
    print(best)
