//find min index i such that a[i]>=x
//query is to change ele at any time and to find expected output

#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=1e5+2,MOD=1e9+7;
int tree[4*N],a[N];

void build(int node,int st,int en){
    if(st==en){
        tree[node]=a[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node]=max(tree[2*node],tree[2*node+1]);
}

int query(int node,int st,int en,int l,int r){
    //not any overlap
    if(st>r || en<l)return -MOD;
    //complete overlap
    if(l<=st && en<=r)return tree[node];
    //partial overlap
    int mid=(st+en)/2;
    int q1=query(2*node,st,mid,l,r);
    int q2=query(2*node+1,mid+1,en,l,r);
    return max(q1,q2);
}

void update(int node,int st,int en,int idx,int val){
     if(st==en){
        a[st]=val;
        tree[node]=val;
     }
     int mid=(st+en)/2;
     if(idx<=mid){
        update(2*node,st,mid,idx,val);
     }else{
        update(2*node+1,mid+1,en,idx,val);
     }
     tree[node]=max(tree[2*node],tree[2*node+1]);
}


signed main()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++)
    cin>>a[i];

   build(1,0,n-1);
   while (m--){
    int type;
    cin>>type;
    if(type==2){
        int x,lo=0,hi=n-1;
        cin>>x;
        int ans=n;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(query(1,0,n-1,lo,mid)<x){
                lo=mid+1;
            }else{
                hi=mid-1;
                ans=min(ans,mid);
            }
        }
        if(ans==n)cout<<-1<<endl;
        else cout<<ans<<endl;
    }else{
        int idx,val;
        cin>>idx>>val;
        update(1,0,n-1,idx,val);
    }
   }
   
   return 0;
}