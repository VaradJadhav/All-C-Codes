//create minheap of pairs {value,array no}
//insert first ele of each array
//pop ele from minheap and store into answer array
//insert next ele of sorted array into minheap
//we also keep track of indices of ele


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(),x.end()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const long long mod = 1e9+7;

void solve(){
    int k;
    cin>>k;
    vector<vector<int>> a(k);
    for(int i=0;i<k;i++){
        int size;
        cin>>size;
        for(int j=0;j<size;j++){
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }
    vector<int> idx(k,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<k;i++){
        pq.push({a[i][0],i});
    }
    vector<int> ans;
    while(!pq.empty()){
        pair<int,int> x=pq.top();
        pq.pop();
        ans.push_back(x.first);
        if(idx[x.second]+1< a[x.second].size())
            pq.push({a[x.second][idx[x.second]+1],x.second});
        idx[x.second]++;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}

signed main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t=1;
//    cin >> t;
   while (t--)
      solve();
      
}
