
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) x.begin(),x.end()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const long long mod = 1e9+7;

void heapify(vector<int> &v,int n,int i){
    int maxIdx=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && v[l]>v[maxIdx])
        maxIdx=l;
    if(r<n && v[r]>v[maxIdx])
        maxIdx=r;
    if(maxIdx!=i){
        swap(v[i],v[maxIdx]);
        heapify(v,n,maxIdx);
    }
}

void heapsort(vector<int> &v){
    int n = v.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(v,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(v[0],v[i]);
        heapify(v,i,0);
    }
}

void solve(){
    int a;
    cin>>a;
    vector<int> v(a);
    for(int i=0;i<a;i++)cin>>v[i];
    heapsort(v);
    for(int i=0;i<a;i++)cout<<v[i]<<" ";
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