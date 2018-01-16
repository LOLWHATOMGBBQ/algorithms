#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

/*
 * Quicksort repeatedly selects a pivot an partitions the range into two. We then 
 * swap elements in the array so that the elements that are less than the pivot
 * element are on the left of the pivot and elements that are greater are on the 
 * right side of the pivot. (Note. elements that are equal to the pivot can be on 
 * either side. We then apply the function on the two partitions on the left and
 * the right of the pivot until we end with an array of size 1 or 0 (sorted array)
 *
 * PROOF:
 * We can prove that this algorithm works through induction (Base cases are the 
 * arrays of size 0 and 1) and the inductive step is something along the lines of 
 * Assume that quicksort works for all arrays of size 0 - N. Then we pick a pivot
 * V and partition the array (of size N+1) into 2 parts P_1 and P_2. Since 
 * 0 <= |P_1|,|P_2| <= N then applying quicksort on both partitions gives us
 * That P_1 is sorted and P_2 is sorted. Since 
 * (index(V), V) >= (index(e), e) for all e in P_1 and
 * (index(V), V) <= (index(e), e) for all e in P_2.
 * Also note that P_1 and P_2 are sorted, so the array is sorted.
 *
 * Despite having a worst case of O(N^2), quicksort is often faster in practice
 * than merge sort and heapsort because of the lower overhead costs.
 *
 * In this algorithm, we chose the pivot to be the middle element of the range to 
 * be sorted. This gives a lower chance of encoutering the worst case (having to
 * swap everything at each iteration)
 * 
 * Time Complexity (Average): O(n log n).
 * Time Complexity (Worst): O(n^2).
 * Space Complexity: O(log n) auxiliary stack space.
 * Stable?: No.
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
