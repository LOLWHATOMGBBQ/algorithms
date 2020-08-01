#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  
  vector<string> all_perms;

  do {
    string sn(s);
    if (!all_perms.empty() && all_perms.back() == sn) {
      continue;
    }

    all_perms.emplace_back(sn);
  } while (next_permutation(s.begin(), s.end()));

  cout << all_perms.size() << '\n';
  for (const string& s : all_perms) {
    cout << s << '\n';
  }

  return 0;
}
