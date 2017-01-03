def mult(A, B):
    return [[sum(i*j for i, j in zip(r, c)) for c in zip(*B)] for r in A]
def lu(A):
    N = len(A)
    L = [[0.0 for i in xrange(N)] for j in xrange(N)]
    U = [[0.0 for i in xrange(N)] for j in xrange(N)]
    # Initializes the pivot matrix
    I = [[1.0 if i==j else 0 for i in xrange(N)] for j in xrange(N)]
    for i in xrange(N):
        row = max(xrange(i, n), key=lambda j: abs(A[j][i]))
        if j != row:
            temp = I[j]
            I[j] = I[row]
            I[row] = temp

    A2 = mult(I, A)
    for j in xrange(N):
        L[j][j] = 1.0
        for i in xrange(j+1):
            s1 = sum(U[k][j] * L[i][k] for k in xrange(i))
            U[i][j] = A2[i][j] - s1
        for i in xrange(j, N):
            s2 = sum(U[k][j] * L[i][k] for k in xrange(j))
            L[i][j] = (A2[i][j] - s2) / U[j][j]
    return (L, U, P)