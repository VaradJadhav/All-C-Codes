/////https://cses.fi/problemset/task/1195


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define see(x) cin >> x
#define sees(x, y) cin >> x >> y
#define put(x) cout << x << " "
#define puts(x) cout << x << endl
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define endl '\n'
const int M = 1e9 + 7, N = 1e6 + 7;


void dij(int s,vector<int> &dis,vector<vector<pair<int,int>>> &adj){
    priority_queue<pair<int,int>> pq;
    vector<int> vis(dis.size(),0);
    dis[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int x=pq.top().first;
        int y=pq.top().second;
        pq.pop();
        if(vis[y])continue;
        vis[y]=1;
        for(auto it:adj[y]){
            if(dis[y]+it.second<dis[it.first]){
                dis[it.first]=dis[y]+it.second;
                pq.push({-dis[it.first],it.first});
            }
        }
        
    }
}

void solve(){
    int m,n,x,y,z,ans=LLONG_MAX;
    cin>>m>>n;
    vector<vector<pair<int,int>>> adj(m),adj1(m);
    vector<int> dis1(m,LONG_MAX),dis2(m,LONG_MAX);
    while(n--){
        cin>>x>>y>>z;
        x--;y--;
        adj[x].push_back({y,z});
        adj1[y].push_back({x,z});
    }
    dij(0,dis1,adj);
    dij(m-1,dis2,adj1);
    for(int i=0;i<m;i++){
        for(auto it:adj[i]){
            ans=min(ans,dis1[i]+dis2[it.first]+it.second/2);
        }
    }
    puts(ans);
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
