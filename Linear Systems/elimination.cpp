#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>

using namespace std;


void elim (vector<vector<float> > matrix, float *values, int length) {
    // Performs row operations on the matrix and reduces it
    // to the form:
    // a_{0,0} a_{0, 1} ... a_{0, length-1}        | b_0
    // 0       a_{1, 1} ... a_{1, length-1}        | b_1
    // 0       0        ... a_{2, length-1}        | b_2
    // .       .        .   .                      | .
    // .       .         .  .                      | .
    // .       .          . .                      | .
    // 0       0        ... a_{length-1, length-1} | b_{length-1}
    for (int i = 0; i < length-1; ++i) {
        for (int j = i+1; j < length; ++j) {
            float multiple;

            if (matrix[j][i] == 0)
                multiple = 0;
            else
                multiple = matrix[j][i]/matrix[i][i];

            for (int k = i; k < length; ++k) {
                matrix[j][k] -= multiple * matrix[i][k];
            }
            values[j] -= multiple * values[i];
        }
    }

    // Solves the system of equations by performing row operations
    // on the matrix and reduces it to the form:
    // a_{0,0} a_{0, 1} ... a_{0, length-1}        | b_0
    // 0       a_{1, 1} ... a_{1, length-1}        | b_1
    // 0       0        ... a_{2, length-1}        | b_2
    // .       .        .   .                      | .
    // .       .         .  .                      | .
    // .       .          . .                      | .
    // 0       0        ... a_{length-1, length-1} | b_{length-1}
    for (int i = length-1; i > 0; --i) {
        values[i] /= matrix[i][i];
        matrix[i][i] = 1;
        for (int j = i-1; j >= 0; --j) {
            float multiple;

            if (matrix[j][i] == 0)
                multiple = 0;
            else
                multiple = matrix[j][i]/matrix[i][i];

            matrix[j][i] = 0;
            values[j] -= values[i] * multiple;
        }
    }
}

int main()
{
    vector<vector<float> > arr (3, vector<float>(3, 0));
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = -1;
    arr[1][0] = 2; arr[1][1] = 2; arr[1][2] = 2;
    arr[2][0] = 1; arr[2][1] = -1; arr[2][2] = 2;
    
    float vals[3] = {2, 12, 5};

    elim(arr, vals, 3);

    for (int i = 0; i < 3; ++i) {
        cout << vals[i] << endl;
    }
    return 0;
}
