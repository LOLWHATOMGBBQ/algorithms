# creates a AB from two points
def vector(pA, pB):
    return [pB[i] - pA[i] for i in xrange(len(pA))]


# calculates the magnitude of a vector
def mag(vec):
    return sum([vec[i] * vec[i] for i in xrange(len(vec))]) ** 0.5


# calculates the dot product of two vectors
def dot(v1, v2):
    return sum([v1[i] * v2[i] for i in xrange(len(v1))])


# calculates the magnitude cross product of two vectors
def cross(v1, v2):
    return sum([v1[i] * v2[i + 1] - v1[i + 1] * v2[i] for i in xrange(len(v1) - 1)])


# Returns a function that checks if
def ccw_cmp(vec1, vec2):
    prod = cross(vec1, vec2)
    return prod if prod == 0 else prod / abs(prod)


# points is a list of points of the form  (x, y)
def conv_hull(points):
    stack = []
    total = len(points)
    min_pt = (9999999, 9999999)
    min_idx = -1
    # find the leftmost point
    for i, pt in enumerate(points):
        if pt < min_pt:
            min_pt = pt
            min_idx = i

    # Swap the currently used point to the beginning
    points[min_idx] = points[0]
    points[0] = min_pt

    # Sort the points by angle
    points.sort(cmp=lambda p1, p2: ccw_cmp(vector(min_pt, p1),
                                           vector(min_pt, p2)))
    # initialize the array
    for i in xrange(2):
        stack.append(points[i])

    # iterate through the sorted array (by angle)
    for i in xrange(2, total):
        # Check if it's counterclockwise (angle is positive)
        while ccw_cmp(vector(stack[-1], stack[-2]), vector(stack[-1], points[i])) <= 0:
            stack.pop()

        stack.append(points[i])

    return stack


if __name__ == "__main__":
    print conv_hull(eval(raw_input()))
