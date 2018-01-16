import bisect

def median(L):
	# Simple median function,
	# Considers two cases: odd length and even length
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
	# Time Complexity: O(2log(N)), where N is the length of the list(s)
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

	# For lists of different lengths, we use the same idea of using divide and conquer,
	# but our base cases get a little trickier.

	elif len(l1) < len(l2):
		if len(l1) == 0:
			return median(l2)
		elif len(l1) == 1:
			# There is a faster method of doing this by observing that l1[0] must be one of;
			# below the median, equal the median, or above the median. We then consider if the 
			# list l2 is currently odd or even.
			# Let N represent the length of the list l2
			# Let M represent the median of the merged lists, l1 and l2
			# If the length of l2 is even, there are three possible cases to consider, with two
			# possible values for the median, l2[N/2] and l2[N/2 + 1]
			# Case 1: l1[0] < M
			#     in this case, we see that l1[0] < l2[N/2] must be true, and thus l1[0] < l2[N/2 + 1]
			#     and thus, l2[N/2] is the meidan
			# Case 2: l1[0] = M:
			#     observe that if l1[0] is the median, then we have l2[N/2] <= l1[0] <= l2[N/2 + 1]
			#     and thus l1[0] is the median
			# Case 3: l1[0] > M
			#     this is the opposite of case 1, l1[0] > l2[N/2 + 1] and thus l1[0] > l2[N/2 + 1]
			#     and thus, l2[N/2 + 1] is the median
			# An interesting observation is that the median overall list in these three cases is always
			# equal to the median of the list of values [l1[0], l2[N/2], l2[N/2 + 1]], so
			# we can simply take the median of the list [l1[0], l2[N/2], l2[N/2 + 1]]
			#
			# If the length l2 is odd, we would end up with an even length list.
			# Depending on where the value l1[0] goes, the median changes. We now have 4 cases to 
			# consider. For the sake of simplicity, we will omit these cases. But we notice that
			# the median of the two lists is just the median of the list below
			# [l1[0], l2[N/2-1], l2[N/2], l2[N/2 +  1]]
			#
			# Again, for simplicity, and cleaner coder, we will just use the slower method 
			# (which happens to have a time complexity of O(log(N)) compared to the faster method with a 
			# time complexity of O(1))

			bisect.insort(l2, l1[0])
			return median(l2)
		else:
			mid1 = len(l1)/2
			mid2 = len(l2)/2

			if l1[mid1] <= l2[mid2]:
				return medianOfTwo(l1[mid1:], l2[:mid2+1])
			else:
				return medianOfTwo(l1[:mid1+1], l2[mid2-1:])
	# Wrapper for cleaner code
	else:
		return medianOfTwo(l2, l1)
