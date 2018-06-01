#include <bits/stdc++.h>


template<class T, class Compare>
void bubblesort(T arr[], int size, Compare comp) {
    for (int i = 0; i < size-1; ++i){
        for (int j = 0; j < size - i - 1) {
            if (arr[j] > arr[j+1])
                std::swap(arr+j, arr+j+1);
        }
    }
}
