#creates a AB from two points
def vector(pA, pB):
	return [pB[i] - pA[i] for i in xrange(len(pA))]
#calculates the magnitude of a vector
def mag(vec):
	return sum([vec[i]*vec[i] for i in xrange(len(vec))])**0.5

#calculates the dot product of two vectors
def dot(v1, v2):
	return sum([v1[i]*v2[i] for i in xrange(len(v1))])
#calculates the magnitude cross product of two vectors
def cross(v1, v2):
	return sum([v1[i]*v2[i+1] - v1[i+1]*v2[i] for i in xrange(len(v1) - 1)])

#point to line distance
#calculates the distance from C to line created by the vector AB from A
#calculated with (AB x AC)/|AB|, where x represents cross product
def dist(pA, pB, pC):
	return cross(vector(pA, pB), vector(pA, pC))/(mag(vector(pA, pB)))

#calculates the area of a polygon given its points
#this is done by calculating the cross product of all vectors from the first
#point in the list
def area(poly):
	return abs(sum([cross(vector(poly[0], poly[i]), vector(poly[0], poly[i+1])) for i in xrange(1, len(poly) - 1)]))/2.0

