
# Gets the magnitude of a vector
def mag(vec):
	return (vec[0]*vec[0] + vec[1]*vec[1])**0.5
# Creates a vector from p1->p2
def vec(p1, p2):
	return (p2[0] - p1[0], p2[1] - p1[1])

# Gives the maximum number of colinear points
def maxColinearPoints(points):
	most = 0
	for i in xrange(len(points)):
		count = {}
		for j in xrange(len(points)):
			if i != j:
				cur = vec(p[i], p[j])
				if cur[0] == 0:
					cur[1] = abs(cur[1])
				elif cur[0] < 0:
					cur = -cur[0], -cur[1]
				size = mag(cur)
				cur = map(lambda x: x/size, cur)
				if cur in count:
					count[cur] += 1
				else:
					count[cur] = 1
		for i in count:
			if count[i] > most:
				most = count[i]
	return most

