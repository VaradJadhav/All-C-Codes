#include<bits/stdc++.h>
using namespace std;

//the edge for which if we remove that 
//multiple components get formed


//we need two arrays here 1]time of insertion 2] lowest time

int timer=1;
void dfs(int node,int parent,vector<int> &vis,
        vector<int> &adj[],int timeIn[],int low[],
        vector<vector<int>> &bridges){
            vis[node]=1;
            timeIn[node]=low[node]=timer;
            timer++;
            for(auto it:adj[node]){
                if(it==parent)continue;
                if(vis[it]==0){
                    dfs(it,node,vis,adj,timeIn,low,bridges);
                    low[node]=min(low[node],low[it]);

                    if(low[it]>timeIn[node]){
                        bridges.push_back({it,node});
                    }
                }else{
                    low[node]=min(low[node],low[it]);
                }
            }
        }
vector<vector<int>> criticalConnections(int n,vector<vector<int>> &connections){
    vector<int> adj[n];
    for(auto it:connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n,0);
    int timeIn[n];
    int low[n];
    vector<vector<int>> bridges;
    dfs(0,-1,vis,adj,timeIn,low,bridges);
    return bridges;
}