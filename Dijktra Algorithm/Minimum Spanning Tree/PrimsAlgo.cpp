#include<bits/stdc++.h>
using namespace std;

//Spanning Tree -> a tree in which we have n nodes and n-1 edges but they all are reachable grom eachother
//Minimum Spanning tree - total sum of all edges should be minimum among all spanning trees

//Prim's Algorithm
//Start from 0th node get smallest edge then make one priority queue and add remaining edges to it then take
// minimum of that and add edges belonging to dest node
//Need of priority queue and visited array

int spanningTree(int V,vector<vector<int>> adj[]){
    priority_queue<pair<int,int>>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> vis(V,0);
    //{wt,node}
    pq.push({0,0});
    while(!pq.empty()){
        auto it:pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;

        if(vis[node]==1)continue;
        vis[node]=1;
        sum += wt;
        for(auto i:adj[node]){
            int adjNode=i[0];
            int edW=i[1];
            if(!vis[adjNode]){
                pq.push({edW,adjNode});
            }
        }
    }
    return sum;
}

//greedy is the intuition
//O(Elog(E))

