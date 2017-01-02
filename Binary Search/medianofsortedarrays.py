import bisect

def median(L):
	if len(L)%2:
		return L[len(L)/2]
	else:
		return (L[len(L)/2] + L[len(L)/2 + 1])/2.0



def medianOfTwo(l1, l2):
	# For lists of the same length, the problem is simple divide and conquer
	#
	# We use a property of the median of an list,
	#     Let N represent the length of the list
	#     Let M represent the median of the list
	#     Let B represent the bottom half of the list; L[:N/2]
	#     Let U represent the upper half of the list; L[N/2+1:]
	# For all elements i in B, i <= M, and
	# For all elements j in U, i >= M.
	#
	# We use this property and we find the medians of l1 and l2, m1 and m2, respectively,
	# and split each list, l1 and l2, into two equally sized partitions. Then, we keep 
	# all of the elements between the medians, and recursively call this function.
	# This works because we are removing an equal amount of terms from both ends of the
	# merged list. 
	# 
	# Time Complexity: O(log(N)), where N is the length of the list(s)
	if len(l1) == len(l2):
		if len(l1) == 1:
			return (l1[0] + l2[0])/2.0
		med1 = median(l1)
		med2 = median(l2)

		if med1 == med2:
			return med1
		elif med1 < med2:
			return medianOfTwo(l1[len(l1)/2:], l2[:len(l2)/2+1])
		else:
			return medianOfTwo(l2[len(l2)/2:], l1[:len(l1)/2+1])
