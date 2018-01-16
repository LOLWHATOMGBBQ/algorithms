#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

/*
 * Merge sort first divides a list into n sublists of 1 or 0 elements each, 
 * then recursively merges the sublists into sorted order until only a single 
 * sorted sublist remains. Merge sort is a stable sort, meaning that it 
 * preserves the relative order of elements which compare equal by operator 
 * < or the custom comparator given.
 *
 * An analogous function in the C++ standard library is std::stable_sort(), except
 * that the implementation here requires sufficient memory to be available. When
 * O(n) auxiliary memory is not available, std::stable_sort() falls back to a 
 * time complexity of O(n log^2 n) whereas the implementation here will simply 
 * fail. Blocksort is a sorting algorithm that uses O(1) auxiliary memory, so 
 * see that if interested
 * 
 * Proof:
 * The proof for mergesort is very similar to the proof for quicksort. A slight 
 * change in the inductive step is necessary as we "merge" two lists together
 *
 * Time Complexity (Average): O(n log n).
 * Time Complexity (Worst): O(n log n).
 * Space Complexity: O(log n) auxiliary stack space and O(n) auxiliary heap space.
 * Stable?: Yes.
*/


template<class It, class Compare>
void mergesort(It lo, It hi, Compare comp) {
  if (hi - lo < 2) {
    return;
  }
  It mid = lo + (hi - lo - 1)/2, a = lo, c = mid + 1;
  mergesort(lo, mid + 1, comp);
  mergesort(mid + 1, hi, comp);
  typedef typename std::iterator_traits<It>::value_type T;
  std::vector<T> merged;
  while (a <= mid && c < hi) {
    merged.push_back(comp(*c, *a) ? *c++ : *a++);
  }
  if (a > mid) {
    for (It it = c; it < hi; ++it) {
      merged.push_back(*it);
    }
  } else {
    for (It it = a; it <= mid; ++it) {
      merged.push_back(*it);
    }
  }
  for (int i = 0; i < hi - lo; i++) {
    *(lo + i) = merged[i];
  }
}


template<class It>
void mergesort(It lo, It hi) {
  typedef typename std::iterator_traits<It>::value_type T;
  mergesort(lo, hi, std::less<T>());
}

