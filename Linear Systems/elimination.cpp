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
    for (int i = 0; i < length; ++i) {
        for (int j = i+1; j < length; ++j) {
            float multiple;

            if (matrix[j][i] == 0)
                multiple = 0;
            else
                multiple = matrix[i][i]/matrix[j][i];

            for (int k = 0; i < length; ++i) {
                matrix[j][k] -= multiple * matrix[i][k];
                values[j] -= multiple * values[i];
            }
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
    vector<vector<float> > arr (2, vector<float>(2, 0));
    arr[0][0] = 1;
    arr[0][1] = -1;

    arr[1][0] = 1;
    arr[1][1] = 1;

    float vals[2] = {-6, 8};

    elim(arr, vals, 2);

    for (int i = 0; i < 2; ++i) {
        cout << vals[i] << endl;
    }
    return 0;
}
