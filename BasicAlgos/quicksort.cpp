#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

/*
Quicksort repeatedly selects a pivot and partitions the range so that elements
comparing less than the pivot precede the pivot, and elements comparing greater
or equal follow it. Divide and conquer is then applied to both sides of the
pivot until the original range is sorted. Despite having a worst case of O(n^2),
quicksort is often faster in practice than merge sort and heapsort, which both
have a worst case time complexity of O(n log n).
The pivot chosen in this implementation is always a middle element of the range
to be sorted. To reduce the likelihood of encountering the worst case, the pivot
can be chosen in better ways (e.g. randomly, or using the "median of three"
technique).
Time Complexity (Average): O(n log n).
Time Complexity (Worst): O(n^2).
Space Complexity: O(log n) auxiliary stack space.
Stable?: No.
*/

template<class It, class Compare>
void quicksort(It lo, It hi, Compare comp) {
  if (hi - lo < 2) {
    return;
  }
  typedef typename std::iterator_traits<It>::value_type T;
  T pivot = *(lo + (hi - lo)/2);
  It i, j;
  for (i = lo, j = hi - 1; ; ++i, --j) {
    while (comp(*i, pivot)) {
      ++i;
    }
    while (comp(pivot, *j)) {
      --j;
    }
    if (i >= j) {
      break;
    }
    std::swap(*i, *j);
  }
  quicksort(lo, i, comp);
  quicksort(i, hi, comp);
}

template<class It>
void quicksort(It lo, It hi) {
  typedef typename std::iterator_traits<It>::value_type T;
  quicksort(lo, hi, std::less<T>());
}
