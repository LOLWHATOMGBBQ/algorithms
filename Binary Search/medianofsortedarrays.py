import bisect

def median(L):
	if len(L)%2:
		return L[len(L)/2]
	else:
		return (L[len(L)/2] + L[len(L)/2 + 1])/2.0


def f(l1, l2):
	if len(l1) == len(l2) == 1:
		return (l1[0] + l2[0])/2.0
