#include<bits/stdc++.h>
using namespace std;
//gfg
//it helps to find shortest path even if there are negative edges
//used for directed graphs
//if graph is undirected we have to change it to directed
//we use bellman ford to detect -ve weight cycles
vector<int> bellman_ford(int V,vector<vector<int>> &edges,int S){
    vector<int> dist(V,1e8);
    dist[S]=0;
    for(int i=0;i<V-1;i++){
        for(auto it:edges){
            int u=it[0],v=it[1],wt=it[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                //relaxation
                dist[v]=dist[u]+wt;
            }
        }
    }
    //V'th relaxation to check -ve cycle
    for(auto it:edges){
        int u=it[0],v=it[1],wt=it[2];
        if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
            return {-1};
        }
    }
    return dist;
}