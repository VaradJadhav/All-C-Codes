// Problem Name: Throwing Dice
// Problem Link: https://cses.fi/problemset/task/1096
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

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> c(6, vector<int>(b[0].size()));
    for (int i = 0; i < 6; i++) 
        for (int j = 0; j < b[0].size(); j++) 
            for ( int k = 0; k < 6; k++) 
                (c[i][j] += a[i][k]*b[k][j]%M)%=M;
    return c;
}

vector<vector<int>> exp(vector<vector<int>> x, unsigned int y){
    vector<vector<int>> res(6, vector<int>(6));
    for ( int i = 0; i < 6; i++) 
        res[i][i] = 1;

    while(y>0){
        if (y&1) {
            res = mul(res,x);
        }
        y=y>>1; 
        x = mul(x,x);
    }
    return res;
}
void solve(){
    vector<vector<int>> x(6, vector<int>(6));
    for (int i = 0; i < 5; i++) 
        x[i][i+1] = 1, x[5][i] = 1;
    x[5][5] = 1;
    int n; cin>>n;
    x = exp(x,n);
    cout<< x[5][5];
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
