#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a%b);
}


struct Rat{
  int num;
  int den;

  Rat() : num{0}, den{1} {}
  Rat(int num, int den) : num{num}, den{den} {
    reduce();
  }

  Rat operator+(const Rat& other) {
    return Rat(num * other.den + den * other.num, den * other.den);
  }

  void reduce() {
    int this_gcd = gcd(num, den);
    num /= this_gcd;
    den /= this_gcd;
  }
};


int T;
int N, p, k;
int arr[50001];
Rat prefix[50001];

bool is_attainable(Rat avg)

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d%d%d", &N, &p, &k);
    for (int i = 0; i < N; ++i) {
      scanf("%d", arr+i);
    }
  }
  
  return 0;
}
