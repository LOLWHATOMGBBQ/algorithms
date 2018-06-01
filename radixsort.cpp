#include <bits/stdc++.h>

// Assumes that T is an unsigned pritmitive type
template<class T>
void radix_sort(T arr[], int size, int bits = 8) {
    if (size < 2) {
        return;
    }
    const int radix_base = 1 << bits;
    const int radix_mask = radix_base - 1; // e.g. 2^8 - 1 = 0xFF    
    
    typedef typename std::iterator_traits<UnsignedIt>::value_type T;
    
    
    std::vector<T>* buf = new std::vector<T>[radix_base];
    
    // Find the maximum value in the array
    T max_val = std::max(arr, arr+size);
    
    for (int mval = base; mval <= max_val; mval <<= 1) {
        for (int i = 0; i < size; ++i) {
            int bucket = arr[i] / (mval) % radix_base;
            buf[bucket].push_back(arr[i])
        }
        
        int arr_idx = 0;
        for (int i = 0; i < radix_base; ++i) {
            // Reorders value based on which bucket the item is in
            for (int val : buf[i]) {
                arr[arr_idx++] = val;
            }
            buf[i].clear();
        }
    }
    
    delete[] buf;
}
