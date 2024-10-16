// There are n cities and m edges connected by some number of flights.
//  You are given an array flights where flights[i] = [fromi, toi, pricei] 
//  indicates that there is a flight from the city fromi to city toi with cost
//   pricei.

// You are also given three integers src, dst, and k, return the cheapest price 
// from src to dst with at most k stops. If there is no such route, return -1


#include<bits/stdc++.h>
using namespace std;

int CheapestFLight(int n, vector<vector<int>>& flights,
    int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        //djkstra algo
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>K)continue;
            for(auto iter:adj[node]){
                int adjNode=iter.first;
                int edgeWeight=iter.second;
                if(cost+edgeWeight<dist[adjNode] && stops<=K){
                    dist[adjNode]=cost+edgeWeight;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }

    //time complexity O(E) only because we are not using any priority queue
    //ie O(flights.size())