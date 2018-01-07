from collections import deque


# Sliding window algorithm
def maxSlidingWindow(nums, k):
    dq = deque()
    best = []
    for i in xrange(len(nums)):
        if dq:
            if i-k >= 0 and nums[i-k] == dq[-1]:
                dq.pop()
            
            while dq and dq[0] < nums[i]:
                dq.popleft()
                
        dq.appendleft(nums[i])
        if i >= k-1:
            best.append(dq[-1])
        
    return best
