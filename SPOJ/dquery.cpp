#include <bits/stdc++.h>

using namespace std;

int n, q;
int arr[30001];
int ans[200001];
// l, r, i
int l, r;
unordered_map<int, int> val_count;
int cur_ans = 0;

void add(int val) {
  ++val_count[val];
  if (val_count[val] == 1)
    ++cur_ans;
}

void remove(int val) {
  --val_count[val];
  if (val_count[val] == 0)
    --cur_ans;
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; ++i)
    scanf("%d", arr+i);

  scanf("%d", &q);
  vector<tuple<int,int,int>> queries;
  queries.reserve(q);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &l, &r);

    queries.push_back(make_tuple(l-1, r-1, i));
  }
  int block_size = ceil(sqrt(n));

  sort(queries.begin(), queries.end(), [&block_size](
        const tuple<int, int, int>& l, const tuple<int, int, int>& r) -> bool {
      if (get<0>(l)/block_size != get<0>(r)/block_size) {
        return get<0>(l) < get<0>(r);
      } else {
        return (get<0>(l)/block_size & 1) ? get<1>(l) < get<1>(r) : get<1>(l) > get<1>(r);
      }
    }
  );

  int cur_l = 0, cur_r = 0;
  add(arr[0]);
  for (const auto&[left, right, index] : queries) {
    while (cur_l < left) {
      remove(arr[cur_l]);
      ++cur_l;
    }
    while (left < cur_l) {
      --cur_l;
      add(arr[cur_l]);
    }
    while (cur_r < right) {
      ++cur_r;
      add(arr[cur_r]);
    }
    while (right < cur_r) {
      remove(arr[cur_r]);
      --cur_r;
    }
    ans[index] = cur_ans;
  }

  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
  }

  return 0;
}
