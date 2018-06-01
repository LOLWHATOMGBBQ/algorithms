#include <bits/stdc++.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = r;
    }
}
/*
 * There's also the recursive implementation which I like a lot
 * which is something like:
 * [](int a, int b) { return (a % b == 0) ? b : gcd(b,a%b);}
 * very nice
 */

// a / gcd(a,b) first because of overflow
int lcm(int a, int b) {
    return abs(a / gcd(a, b) * b);
}


// Returns a pair of integers such that gcd(a, b) = a*x + b*y
std::pair<int, int> extended_euclid(int a, int b) {
    int x = 1, y = 0, x1 = 0, y1 = 1;
    while (b != 0) {
        int q = a/b, prev_x1 = x1, prev_y1 = y1, prev_b = b;
        x1 = x - q*x1;
        y1 = y - q*y1;
        b = a - q*b;
        x = prev_x1;
        y = prev_y1;
        a = prev_b;
    }
    
    return (a > 0) ? std::make_pair(x, y) : std::make_pair(-x, -y);
}
// Again there's also the recurive version but I won't bother

int mod_inverse(int a, int m) {
    return (extended_euclid(a, m).first % m + m)%m;
}
