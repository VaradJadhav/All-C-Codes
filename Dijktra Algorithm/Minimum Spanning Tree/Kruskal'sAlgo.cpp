#include<bits/stdc++.h>
using namespace std;


//helps us to find minimum spanning tree
//1]Sort all the edges according to weights
//2]iterate on all these edge and use the disjoint set concept to check if that edge neccesary to take or not
//3]if both u and v are not in same component then we will take that egdge to the tree

//ie if both are already in same component then after adding this edge cycles will be formed

class DisjointSet{
    vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }
        int findUPar(int node){
            if(node==parent[node])return node;
            return parent[node]=findUPar(parent[node]);
        }//path compression
        void unionByRank(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v)return;
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }else if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v]=ulp_u;
            }else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);
            if(ulp_u==ulp_v)return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};

int spaningTree(int V,vector<vector<int>> adj[]){
    vector<pair<int,pair<int,int>>> edges;
    //O(N+E)
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            edges.push_back({it[1],{i,it[0]}});
        }
    }
    //O(MlogM)
    sort(edges.begin(),edges.end());
    int mstWt=0;
    DisjointSet ds(V);
    //M*4*alpha
    for(auto it:edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;

        if(ds.findUPar(u) != ds.findUPar(v)){
            mstWt += wt;
            ds.unionBySize(u,v);
        }
    }
    return mstWt;
}

