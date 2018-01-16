# find the largest area of the "lines"
# where each line connects from (i, 0) to (i, height[i])
# so it's like the largest container sorta

def maxArea(height):
    n = len(height)
    lidx = 0
    ridx = n-1
    lheight = height[0]
    rheight = height[-1]
    best = min(lheight, rheight)*(n-1)
    
    while lidx < ridx:
        print min(lheight, rheight)*(ridx - lidx)
        best = max(best, min(lheight, rheight)*(ridx - lidx))
        
        if lheight < rheight:
            lidx += 1
            lheight = height[lidx]
        else:
            ridx -= 1
            rheight = height[ridx]
    return best
    
