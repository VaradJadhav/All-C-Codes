#include<bits/stdc++.h>
using namespace std;

//for sum of any range finding
//update - O(logn)
//find - O(logn)

const int N=100;
int a[N],tree[4*N];

void build(int node,int st,int en){
    if(st==en){
        tree[node]=a[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node] = tree[2*node] + tree[2*node+1];
    //2*n+1 == 2*n|1
}

int query(int node,int st,int en,int l,int r){
    if(st>r || en<l){
        return 0;
        //here we have to decide as per question what to return
    }
    if(l<=st && en<=r){
        return tree[node];
    }
    int mid=(st+en)/2;
    int q1=query(2*node,st,mid,l,r);
    int q2=query(2*node+1,mid+1,en,l,r);
    return (q1+q2);
}

int main()
{
   int t;
   cin>>t;
   for(int i=0;i<t;i++)cin>>a[i];
   build(1,0,t-1);
   for(int i=1;i<15;i++){
    cout<<tree[i]<<" ";
   }
   cout<<endl;
   while(1){
    int type;
    cin>>type;
    if(type==-1)break;
    if(type==1){
        //for querry
        int l,r;
        cin>>l>>r;
        int ans=query(1,0,t-1,l,r);
        cout<<ans<<endl;
    }
   }
   return 0;
}