#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  int N;
  cin >> N;

  set<int> uniq;
  for (int i = 0; i < N; ++i) {
    int v;
    cin >> v;
    uniq.insert(v);
  }

  cout << uniq.size() << '\n';

  return 0;
}

