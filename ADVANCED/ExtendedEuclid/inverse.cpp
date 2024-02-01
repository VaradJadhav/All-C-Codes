#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll x1, y1;
  ll d = extended_euclid(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
ll inverse(ll a, ll m) {
  ll x, y;
  ll g = extended_euclid(a, m, x, y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll x = 100, m = 23;
  cout << inverse(x, m) << '\n';
  return 0;
}



// int gcd(int a, int b, int& x, int& y) {
//     x = 1, y = 0;
//     int x1 = 0, y1 = 1, a1 = a, b1 = b;
//     while (b1) {
//         int q = a1 / b1;
//         tie(x, x1) = make_tuple(x1, x - q * x1);
//         tie(y, y1) = make_tuple(y1, y - q * y1);
//         tie(a1, b1) = make_tuple(b1, a1 - q * b1);
//     }
//     return a1;
// }