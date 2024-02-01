// Problem Name: Graph Paths I
// Problem Link: https://cses.fi/problemset/task/1723
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
// const int mod=1e9+7,inf=(1LL<<62);


// Consider a directed graph that has n
//  nodes and m
//  edges. Your task is to count the number of paths from node 1
//  to node n
//  with exactly k
//  edges.
vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) 
        for (int j = 0; j < b[0].size(); j++)
            for ( int k = 0; k < a[0].size(); k++) 
                (c[i][j] += a[i][k]*b[k][j]%M)%=M;
    return c;
}


vector<vector<int>> exp( vector<vector<int>> x, int y) {
    vector<vector<int>> r(x.size(), vector<int>(x.size()));
    for ( int i = 0; i < x.size(); i++) r[i][i] = 1;
    while (y>0){
        if (y&1) {
            r = mul(r,x);
        }
        y=y>>1;
        x = mul(x,x);
    }
    return r;
}
void solve(){
    //considering multiple edges
    int n,m, k; cin>>n>>m>>k;
    vector<vector<int>> adj(n,vector<int>(n));
    for (int i = 0; i< m; i++) {
        int x,y; cin>>x>>y;
        x--; y--;
        adj[x][y]++;
    }
    adj = exp(adj,k);
    cout<<adj[0][n-1];
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
