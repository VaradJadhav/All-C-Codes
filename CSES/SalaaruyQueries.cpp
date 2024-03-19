// Problem Name: Salary Queries
// Problem Link: https://cses.fi/problemset/task/1144
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define oset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>


void solve(){
    oset s;
    int n,k; cin>>n>>k;
    int a[n+1]; 
    for(int i=1;i<=n;i++)cin>>a[i];
    rep(i,1,n+1){
        s.insert(a[i]);
    }
    while(k--){
        char x; int y,z; see(x,y,z);
        if (x=='?'){
            cout<<(s.order_of_key(z+1) - s.order_of_key(y))<<" ";
        }
        else{
            s.erase(s.find_by_order(s.order_of_key(a[y])));
            a[y] = z;
            s.insert(z);
        }
    }
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
