import numpy as np
import pandas as pd

def perceptron(X, Y, w, b, iterations):
  N, D = X.shape
  mistakes = [0 for i in range(max_pass)]
  for t in range(max_pass):
    for index, row in X.iterrows():
      if Y.loc[index][0]*(row.dot(w) + b) <= 0:
        w = w + Y.loc[index][0]*row
        b = b + Y.loc[index][0]*row
        mistakes[t] = mistakes[t] + 1
  return w, b, mistakes
