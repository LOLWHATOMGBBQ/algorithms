#include <bits/stdc++.h>

using namespace std;


int N, K;
int arr[300001];
// prefix[i] = a[i-1] + a[i-2] + ... + a[0]
// sum [l, r) = prefix[r] - prefix[l]
// sum [l, r] = prefix[r+1] - prefix[l]
double prefix[300001] = {0.0};

bool is_atainable(double avg) {
  prefix[0] = 0.0;
  for (int i = 0; i < N; ++i) {
    prefix[i+1] = prefix[i] + static_cast<double>(arr[i]) - avg;
  }
  double min_prev = 0;
  for (int i = K-1; i < N; ++i) {
    min_prev = min(min_prev, prefix[i+1-K]);
    if (prefix[i+1] - min_prev >= 0.0)
      return true;
  }
  return false;
}

double bisect(double lower, double upper) {
  // get max avg
  double mid = (upper + lower)/2.0;

  if (upper - lower < 0.00001) {
    return mid;
  } else if (is_atainable(mid)) {
    return bisect(mid, upper);
  } else {
    return bisect(lower, mid);
  }
}

int main() {
  cin >> N >> K;


  double upper = 1e6;
  double lower = 0;

  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    upper = max(upper, static_cast<double>(arr[i]));
    lower = min(lower, static_cast<double>(arr[i]));
  }

  printf("%.06lf\n", bisect(lower, upper));
}
