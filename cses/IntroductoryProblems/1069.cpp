#include <bits/stdc++.h>

using namespace std;

string s;
char last = 0;
int cnt = 1;
int best = 0;

int main() {
  cin >> s;
  
  for (char c: s) {
    if (c == last)
      cnt++;
    else {
      cnt = 1;
      last = c;
    }
    best = max(best, cnt);
  }

  cout << best << '\n';
}
