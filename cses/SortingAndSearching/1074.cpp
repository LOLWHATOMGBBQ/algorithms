#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  vi arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  ll tot = 0;
  ll median = arr[N/2];
  for (int i = 0; i < N; ++i) {
    tot += abs(median - arr[i]);
  }
  cout << tot << '\n';
  
  return 0;
}

