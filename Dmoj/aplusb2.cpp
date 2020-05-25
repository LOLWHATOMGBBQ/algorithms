#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100001] = {};

int main() {
  cin >> N;
  for (int _ = 0; _ < N; ++_) {
    string a, b;

    cin >> a >> b;
    if (a.size() < b.size())
      swap(a, b);
    bool is_a_neg = false;
    if (a[0] = '-')
      is_a_neg = true;
    bool is_b_neg = false;
    if (b[0] = '-')
      is_b_neg = true;

    reverse(a.begin(), a.end());
    // remove the -
    if (is_a_neg)
      a.pop_back();
    reverse(b.begin(), b.end());
    // remove the -
    if (is_b_neg)
      b.pop_back();

    int LA = a.length();
    int LB = b.length();
    int L = max(LA, LB);
    int len_result = 0;
    bool is_neg = false;

    if (is_a_neg == is_b_neg) {
      // normal addition
      int carry = 0;
      for (int i = 0; i < L; ++i) {
        int a_val = i < LA ? a[i] - '0' : 0;
        int b_val = i < LB ? b[i] - '0' : 0;
        
        int result = a_val + b_val + carry;
        if (result)
          len_result = i;
        arr[i] = result%10;
        carry = result/10;
      }
      if (carry) {
        len_result = L+1;
        arr[L] = carry;
        carry = 0;
      }
      // print here if neg then do else
      is_neg = is_a_neg;
    } else {
      // subtraction
      bool borrow = false;
      for (int i = 0; i < L; ++i) {
        int a_val = i < LA ? a[i] - '0' : 0;
        int b_val = i < LB ? b[i] - '0' : 0;
        
        // a_val-b_val
        int result = a_val-borrow-b_val;

        arr[i] = (10+result)%10;
        borrow = result < 0;
        if (result)
          len_result = i;
      }
      if (borrow) {
        // then we have to flip the whole string
        len_result = L+1;
        // 10^{L+1} - c
        int prev = 10;
        for (int i = L; i >= 0; --i) {
          int c_val = c[i] - '0';
          int result = prev-c_val;
        }
      }
      // print here
    }
    
  }
}
