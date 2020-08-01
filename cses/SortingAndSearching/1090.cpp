#include <bits/stdc++.h>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, X;
  cin >> N >> X;

  vi children(N);
  for (int i = 0; i < N; ++i) {
    cin >> children[i];
  }

  sort(children.begin(), children.end());

  int beg = 0, end = N-1;

  int gondolas = 0;
  while (beg < end) {
    if (children[beg] + children[end] <= X) {
      ++beg;
      --end;
      ++gondolas;
    } else {
      --end;
      ++gondolas;
    }
  }
  if (beg == end)
    ++gondolas;

  cout << gondolas << '\n';

  return 0;
}

