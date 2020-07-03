#include <bits/stdc++.h>

using namespace std;

int cur, last = INT_MAX;
int N;
long long int tot = 0;

int main() {
  scanf("%d", &N);
  scanf("%d", &last);
  
  for (int i = 1; i < N; ++i) {
    scanf("%d", &cur);
    tot += max(0, last - cur);

    last = max(last, cur);
  }

  cout << tot << '\n';
}
