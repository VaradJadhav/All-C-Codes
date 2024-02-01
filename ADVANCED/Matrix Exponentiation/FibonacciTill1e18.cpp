
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// #define see(x) cin >> x
// #define sees(x, y) cin >> x >> y
// #define put(x) cout << x << " "
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define endl '\n'
const int M = 1e9 + 7, N = 1e6 + 7;
const int mod=1e9+7,inf=(1LL<<62);

pair<int,int> fib(int n){
    if (n==0){
        return {0,1};
    }
    pair<int,int> p = fib(n>>1);
    int c = p.first*(2*p.second - p.first + M)%M;
    int d = (p.first*p.first%M + p.second*p.second%M)%M;
    if (n&1) return {d,(c+d)%M};
    else return {c,d};
}

void solve(){
    int n; cin>>n;
    cout<<(fib(n).first);
}   

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    // check();
    while (t--)
    {
        solve();
    }
}
