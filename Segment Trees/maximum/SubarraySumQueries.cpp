// Problem Name: Subarray Sum Queries
// Problem Link: https://cses.fi/problemset/task/1190
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

int seg[1000005][4], n;
//max, pre, suff, total
void update(int k, int x) {
    k+=n;
    rep(i,0,4) seg[k][i] = x;
    k>>=1;
    while(k>0) {
        seg[k][0] = max({seg[2*k][0], seg[2*k+1][0], seg[2*k][2] + seg[2*k+1][1], 0LL}); //max
        seg[k][1] = max({seg[2*k][1], seg[2*k][3] + seg[2*k+1][1], 0LL}); //pre
        seg[k][2] = max({seg[2*k][2] + seg[2*k+1][3], seg[2*k+1][2], 0LL}); //suff
        seg[k][3] = seg[2*k][3] + seg[2*k+1][3]; //total
        k>>=1;
    }
}
void solve(){
    int nn,q; cin>>(nn,q);
    n = pow(2,ceil(log2(nn)));
    rep(i,0,nn) {
        int x; cin>>(x);
        update(i,x);
    }
    while(q--) {
        int k,x; cin>>(k,x);
        update(k-1,x);
        cout<<(seg[1][0])<<endl;
    }
} 

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    // check();
    while (t--)
    {
        solve();
    }
}
