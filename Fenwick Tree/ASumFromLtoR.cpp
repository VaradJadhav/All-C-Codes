#include<bits/stdc++.h>
using namespace std;
const int N=6;
int fen[N];
void update(int i,int add){
    while(i<=N){
        fen[i]+=add;
        i += (i&(-i));
    }
}


int sum(int i){
    int s=0;
    while(i>0){
        s+=fen[i];
        i=i-(i&(-i));
    }
    return s;
}

int rangeSum(int l,int r){
    return sum(r)-sum(l-1);
}

//we can find lower bound of prefix sum array in logn time complexity
//also with the help of fenwick tree algo
int findLowerBound(int k){
    int curr=0,ans=0,preSum=0;
    for(int i=log2(N);i>=0;i--){
        if(fen[curr+(1<<i)]+preSum<k)
        {
            curr=curr+(1<<i);
            preSum += fen[curr];
        }
    }
    return (curr+1);
}

int main()
{
   int t;
   cin>>t;
   for(int i=1;i<=N;i++){
    update(i,t);
   }
   cout<<rangeSum(1,5)<<endl;
   cout<<findLowerBound(14)<<endl;
   for(int i=0;i<N;i++)cout<<fen[i]<<" ";
   return 0;
}