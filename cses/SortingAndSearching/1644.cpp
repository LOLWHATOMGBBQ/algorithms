#include <bits/stdc++.h>
#include <climits>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vector<long long> prefix;
ll getSum(int start, int cur) {
  return prefix[cur] - prefix[start];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, A, B;

  cin >> N >> A >>B;
  // arr is 1-indexed
  vi arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  prefix = vector<ll>(N+1);
  // prefix[i] = \sum_{i+1}^{A+i+1} arr[i]
  for (int i = 0; i < N; ++i) {
    prefix[i+1] = prefix[i] + arr[i];
  }

  ll cur_best = LLONG_MIN;
  deque<int> starts;

  // [beg_idx, end_idx)
  for (int i = 0, j = A; j <= N; ++i, ++j) {
    if (j-starts.front() > B) {
      starts.pop_front();
    }
    while (!starts.empty()) {
      // getSum(starts.back()) 
      if (getSum(starts.back(), j) <= getSum(i, j)) {
        starts.pop_back();
      } else {
        break;
      }
    }
    starts.push_back(i);

    cur_best = max(cur_best, getSum(starts.front(), j));
  }

  cout << cur_best << '\n';

  return 0;
}

