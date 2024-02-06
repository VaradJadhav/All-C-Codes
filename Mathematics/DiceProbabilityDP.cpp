// Problem Name: Dice Probability
// Problem Link: https://cses.fi/problemset/task/1725
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

void solve(){
    int n,a,b; cin>>n>>a>>b;
    double dp[605][105]={0};
    dp[0][0] = 1.0;
    for (int j = 1; j<=n; j++) {
        for (int i = 1; i < 601; i++) {
            for (int k = 1; k < 7; k++) {
                if (i-k>=0) dp[i][j] += dp[i-k][j-1]*(1.0/6);
            }
        }
    }
    double ans =  0;
    for (int i = a; i <=b; i++) ans+= dp[i][n];
    cout<<setprecision(6)<<fixed;
    cout<<ans;
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
