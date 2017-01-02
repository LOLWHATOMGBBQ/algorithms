# "cross product" on two vectos
def cross(v1, v2):
	return v1[0]*v2[1] - v1[1]*v2[0]
# Converts two points into a vector from p1->p2
def vec(p1, p2):
	return (p2[0] - p1[0], p2[1] - p1[1])

# Assumes len(points) >= 3
def convexHull(points):
	# First find the point with the lowest y valu
	min_idx = 0
	for i in xrange(1, len(points)):
		if points[i][1] < points[min_idx][1]:
			min_idx = i
	min_point = points.pop(min_idx)

	# Sort their point by their angle with respect to the min point and the x-axis
	# so that we can iterate through the points clockwise (sorts in counter clockwise order)
	points.sort(cmp = lambda p1, p2: cross(vec(min_point, p1), vec(min_point, p2)))
	
	stack = [min_point, points.pop()]
	while points:
		cur = points.pop()
		# We will use cross product to determine if something takes a right or left turn
		# if it is less than 0, then we took a left turn, which means its part of the 
		# convex hull. If its not then we remove the previous point and add the current
		# point
		if cross(vec(stack[-1], stack[-2]), vec(stack[-1], cur)) < 0:
			stack.append(cur)
		else:
			stack.pop()
			stack.append(cur)

	return stack

