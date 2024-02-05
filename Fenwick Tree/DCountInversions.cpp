#include<bits/stdc++.h>
using namespace std;

//two ele form inversion if v[i]>v[j] and i<j

//Approach
//Convert array in its relative ordering ie give 1 to smallest ele
vector<int> bit;
int getSum(int idx){
    int sum=0;
    while(idx>0){
        sum += bit[idx];
        idx -= idx&(-idx);
    }
    return sum;
}

void update(int n,int idx,int inc){
    while(idx<=n){
        bit[idx] += inc;
        idx += idx&(-idx);
    }
}

int main()
{
   int n;
   cin>>n;
   vector<int> v(n);
   for(auto &i:v){
    cin>>i;
   }
   vector<int> temp=v;
   sort(temp.begin(),temp.end());

   for(int i=0;i<n;i++){
    v[i]=lower_bound(temp.begin(),temp.end(),v[i])-temp.begin()+1;
   }
   bit=vector<int> (n+1);
   int inv=0;
   for(int i=n-1;i>=0;i--){
    inv += getSum(v[i]-1);
    update(n,v[i],1);
   }
   cout<<inv<<endl;
   
   return 0;
}