#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,prefixSum=0;
   cin>>a;
   //array only contains 1 and -1
   vector<int> v(a);
   map<int,int> m;
   for(int i=0;i<a;i++){
    cin>>v[i];
    prefixSum+=v[i];
    m[prefixSum]++;
   }
   int ans=0;
   for(auto it:m){
    ans += it.second*(it.second-1)/2;
    if(it.first==0)ans += it.second;
   }
   cout<<ans<<endl;
   return 0;
}