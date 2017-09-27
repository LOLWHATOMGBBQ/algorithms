# your code goes here
# Attack of the Blooks http://wcipeg.com/problem/acmtryouts2b
# Use of Dynamic Programming, and Binary Search
#
# Optimization #1:
# So basically we suppose there is a tower at C with radius R and dealing D damage
# So it deals at a constant rate D per second
# So we increment the range from [C - R, C + R] by D
# We can do this in a faster way by simply adding D to arr[C-R]
# and subtracting D from [C+R+1], (See difference arrays if this concept is new)
# We then take the prefix sum at each index to get the "Damage at each point" array
#
# Optimization #2:
# We could just stop here and just let the Bloons pass through with a for loop,
# but there is another trick we can use since all Bloons start at index 1
# We know that for all 1<= i <= N, arr[i] >= 0. So if we take the prefix sum
# of this array, we end up with the "Total damage dealt up to this point" array.
# We can then binary search this array (since in the original array each element >= 0,
# so the prefix must be greater than 0),
# And we binary search for the minimum index such that the element "fits" into the
# Prefix array. (i.e. the largest index where TotalDamage < Health), while maintaining
# sorted order
#
# All in all, we end up with a time complexity of
# O(L) --> From initializing the entire path
# O(N) --> From adding in the towers
# O(N) --> From converting array from difference array to normal to prefix sum
# O(MlogL) --> From finding where the bloons can go to
import sys, bisect
raw_input = sys.stdin.readline

T = int(raw_input())
for _ in xrange(T):
	L, N = map(int, raw_input().split())
    # Initializing the entire path
	cells = [0 for i in xrange(L+1)]
	for i in xrange(N):
		C, R, D = map(int, raw_input().split())
        # Incrementing the range
		cells[max(0, C - R - 1)] += D
		cells[min(L, C + R)] -= D

    # Converting from difference array to standard
	for i in xrange(1, L+1):
		cells[i] += cells[i-1]
    # Converting from standard to prefix sum
	for i in xrange(1, L+1):
		cells[i] += cells[i-1]
    # Actually the above process can be done in just 1 for loop,
    # I'm just too lazy to actually do it

    # Here we input all of the bloons and their healths
	M = int(raw_input())
	for i in xrange(M):
		health = int(raw_input())
        # Binary search for insertion index
        # I could also have made this faster but it's asympotically
        # the same, so it doesn't really matter
		index_end = bisect.bisect_right(cells, health)
		index_beg = bisect.bisect_left(cells, health)
		if index_end > L:
			print "Bloon leakage"
		else:
			print (index_beg if cells[index_beg] == health else index_end) + 1
		
