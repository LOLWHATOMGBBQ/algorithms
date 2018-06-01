#include <bits/stdc++.h>

using namespace std;

// Overall this uses O(NlogN) memory (it uses O(N) memory logN times)
void fft(vector<complex>& x)
{
    const int N = x.size();
    if (N <= 1) return;
 
    // The trick here is that we notice that
    // X_K = \sum_{n=0}^{N-1} e^{-2\pi i k \cdot(n/N)}x^n
    // Which we pre calculate some values and just distribute it as required
    vector<complex> even = x[std::slice(0, N/2, 2)];
    vector<complex> odd = x[std::slice(1, N/2, 2)];
 
    fft(even);
    fft(odd);
 
    // Combines the two ffts into the original array
    for (size_t k = 0; k < N/2; ++k)
    {
        complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
        x[k    ] = even[k] + t;
        x[k+N/2] = even[k] - t;
    }
}
 
