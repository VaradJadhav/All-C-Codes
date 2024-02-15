
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(),x.end()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const long long mod = 1e9+7;

void solve(){
    priority_queue<int,vector<int>> maxHeap;
    maxHeap.push(2);
    maxHeap.push(3);
    maxHeap.push(1);
    cout<<maxHeap.top()<<endl;
    maxHeap.pop();
    cout<<maxHeap.top()<<endl;

    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(2);
    minHeap.push(3);
    minHeap.push(1);
    cout<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<minHeap.top()<<endl;    
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