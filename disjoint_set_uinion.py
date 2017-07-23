
# Solves
# https://www.hackerrank.com/challenges/merging-communities/problem
N, Q = map(int, raw_input().split())


# Declare intial values
arr = [i for i in xrange(N+1)]
size_arr = [1 for i in xrange(N+1)]


# so my algorithm works like:
# On update we have to sets containing {a_i, ..., a_n}
# and {b_i, ..., b_n}
# Let's represent it as tree of height 1 (with directed edges pointing at the root)
#       b_i             a_i
#      ^   ^           ^   ^
#     / ... \         / ... \
#   b_j ...  b_k    a_j ...  a_k
# So ezpz we just point one of the roots over
#       b_i   --------> a_i
#      ^   ^           ^   ^
#     / ... \         / ... \
#   b_j ...  b_k    a_j ...  a_k
# we also do some path compression to make things even faster 
# but above is the general idea

def findRoot(idx, prev = -1):
	if idx == prev:
		return idx
	else:
		return findRoot(arr[idx], idx)
def updatePath(idx, val, prev = -1):
	if idx != prev:
		next = arr[idx]
		arr[idx] = val
		updatePath(next, val, idx)

def printSize(idx):
	return size_arr[findRoot(idx)]
def union(set1, set2):
	# find the roots of the two nodes
	set1_root = findRoot(set1)
	set2_root = findRoot(set2)

	if set1_root == set2_root:
		return
	arr[set1_root] = set2_root
	# compress graph
	updatePath(set1, set2_root)
	# update size
	size_arr[set2_root] += size_arr[set1_root]



for i in xrange(Q):
	inp = raw_input().split()

	if inp[0] == "Q":
		print printSize(int(inp[1]))
	else:
		union(int(inp[1]), int(inp[2]))

