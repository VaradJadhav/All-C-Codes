// Problem Name: Graph Paths II
// Problem Link: https://cses.fi/problemset/task/1724
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
// const int M = 1e9 + 7, N = 1e6 + 7;
// const int mod=1e9+7,inf=(1LL<<62);

#define vi vector<int>
#define vvi vector<vi>
const int inf = 1LL<<60;
const int md = 1000000007;

vvi mul(vvi a, vvi b) {
    vvi c(a.size(), vi(b[0].size()));
    int n = a.size();
    for (int i = 0; i < n; i++) 
        for (int j = 0; j< n; j++) c[i][j] = inf;
    for (int i = 0; i < a.size(); i++) 
        for (int j = 0; j < b[0].size(); j++)
            for ( int k = 0; k < a[0].size(); k++) 
                c[i][j] = min(c[i][j], a[i][k]+b[k][j]);
    return c;
}


vvi exp( vvi x, int y) {
    vvi r(x.size(), vi(x.size()));
    int f = 0;
    while (y>0){
        if (y&1) {
            if (f) r = mul(r,x);
            else r = x, f =1;
        }
        y=y>>1;
        x = mul(x,x);
    }
    return r;
}
void solve(){
    //considering multiple edges
    int n,m, k; cin>>n>>m>>k;
    vvi adj(n,vi(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j< n; j++) adj[i][j] = inf;
    for (int i = 0; i< m; i++) {
        int x,y,c; cin>>x>>y>>c;
        x--; y--;
        adj[x][y] = min(adj[x][y], c);
    }
    adj = exp(adj,k);
    if (adj[0][n-1] < inf) cout<<adj[0][n-1];
    else cout<<-1;
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
