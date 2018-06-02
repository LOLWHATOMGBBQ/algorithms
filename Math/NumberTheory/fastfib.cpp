#include <bits/stdc++.h>

using namespace std;


class Mat {
    // That's what the matrix looks like
    int a, b, 
        c, d;

    Mat(int a, int b, int c, int d) a{a}, b{b}, c{c}, d{d} {}
    
    Mat& operator+(Mat&& other) {
        return Mat(this->a+other.a, this->b+other.b,
                   this->c+other.c, this->d+other.d);
    }
    
    Mat& operator*(Mat&& other) {
        return Mat(this->a*other.a + this->b*other.c, this->a*other.b + this->b*other.d,
                   this->c*other.a + this->d*other->c, this->c*other.b + this->d*other.d);
    }
    
    Mat& operator%(int val) {
        return Mat(this->a % val, this->b % val, this->c % val, this->d % val);
    }
}

// Eulers power formula
Mat& pow(Mat a, int exponent) {
    if (exponent&1) { // If it's odd
        Mat temp = a*a;
        // returns a*()
        return a*pow(a, exponent/2);
    }
    else {
        return pow(a*a, exponent/2);
    }
}

Mat& pow(Mat a, int exp, int mod) {
    if (exponent&1) { // If it's odd
        Mat temp = ((a%mod)*(a%mod)) % mod;
        // returns a*()
        return (a%mod)*(pow(a, exponent/2)) % mod;
    }
    else {
        return pow((a*a)%mod, exponent/2, mod);
    }
}

int fib(int n, int mod = -1) {
    Mat mat = Mat(1, 1, // Recurrence is f(i) + f(i+1) = f(i+2)
                  1, 0); // gives back 0*f(i)+ f(i+1) =  f(i+1)
    // Starts with f(1)= 1, f(2) = 2
    if (mod == -1){
        return pow(mat, n).c;
    }
    else {
        return pow(mat, n, mod).c;
    }
}
