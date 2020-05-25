#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

using namespace std;

int N, Q;
int l, r;


int segments[200001] = {};
long long int query(int index) {
  long long int cur_sum = 0;
  for (; index; index -= index & (-index)) {
    cur_sum += segments[index];
  }
  return cur_sum;
}
void update(int index, int val) {
  // get the first bit y = x - (x&(-x))
  for (; index <= N; index += index & (-index)) {
    segments[index] += val;
  }
}

int main() {
  scanf("%d", &N);
  vector<int> arr;
  arr.reserve(N);
  vector<int> arr_copy;
  arr_copy.reserve(N);

  for (int i = 0; i < N; ++i) {
    int v;
    scanf("%d", &v);
    arr.push_back(v);
    arr_copy.push_back(v);
  }
  sort(arr_copy.begin(), arr_copy.end());
  for (int i = 0; i < N; ++i) {
    // get the index
    // convert to [1...n]
    arr[i] = 1+(lower_bound(arr_copy.begin(), arr_copy.end(), arr[i]) - arr_copy.begin());
    // printf("arr[%d]: %d\n", i, arr[i]);
  }

  scanf("%d", &Q);
  vector<tuple<int,int,int>> queries;
  queries.reserve(Q);
  for (int i = 0; i < Q; ++i) {
    scanf("%d %d", &l, &r);
    queries.push_back(make_tuple(l-1, r-1, i));
  }

  int block_size = ceil(sqrt(N));
  sort(queries.begin(), queries.end(), [&block_size](
        const tuple<int, int, int>& lhs,
        const tuple<int, int, int>& rhs) {
      if (get<0>(lhs)/block_size != get<0>(rhs)/block_size) {
        return get<0>(lhs) < get<0>(rhs);
      } else {
        return (get<0>(lhs)/block_size & 1) ? 
          get<1>(lhs) < get<1>(rhs) : 
          get<1>(lhs) > get<1>(rhs);
      }
      });

  int curL = 0;
  int curR = 0;
  long long int cur_ans = query(arr[0]-1);
  update(arr[0], 1);
  // current range is [0, 0]

  vector<long long int> ans(Q, 0);
  
  for (const auto&[left, right, index] : queries) {
    // printf("%d : (%d, %d) -> (%d, %d)\n", index, curL, curR, left, right);

    while (curL < left) {
      // remove all inversions of values below arr[curL]
      cur_ans -= query(arr[curL]-1);
      update(arr[curL], -1);
      ++curL;
    }
    while (curL > left) {
      --curL;
      // add
      cur_ans += query(arr[curL]-1);
      update(arr[curL], 1);
    }

    while (curR < right) {
      ++curR;
      // add
      // inversions that r on range [l, r-1]: find i in range [l, r-1]
      // count the number of elements that are larger (arr[curR], N]
      cur_ans += query(N) - query(arr[curR]);
      update(arr[curR], 1);
    }
    while (curR > right) {
      // remove
      cur_ans -= query(N) - query(arr[curR]);
      update(arr[curR], -1);
      --curR;
    }
    ans[index] = cur_ans;
  }

  for (const auto& a : ans)
    printf("%lld\n", a);

  return 0;
}
