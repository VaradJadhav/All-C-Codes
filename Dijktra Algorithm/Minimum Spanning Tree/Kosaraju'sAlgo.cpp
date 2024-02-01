#include<bits/stdc++.h>
using namespace std;

//SCC - Strongly connected components
//the component in which each node is reachable from each other node
//only in directed graph

// 1] Sort all nodes according to their finishing time
// 2] reverse the graph
// 3]Do dfs

void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,st);
        }
    }
    st.push(node);
}
void dfs3(int node,vector<int> &vis,vector<int> &adjT[]){
    vis[node]=1;
    for(auto it:adjT[node]){
        if(!vis[it]){
            dfs(it,vis,adjT);
        }
    }
}
int kasaraju(int V,vector<int> adj[]){
    vector<int> vis(V,0);
    stack<int> st;
    //O(V+E)
    for(int i=0;i<V;i++){
        if(!vis[i])dfs(i,vis,adj,st);
    }

    vector<int> adjT[V];
    // O(V+E)
    for(int i=0;i<V;i++){
        vis[i]=0;
        for(auto it:adj[i]){
            adjT[it].push_back(i);
        }
    }
    int scc=0;
    // O(V+E)
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfs3(node,vis,adjT);
        }
    }
    return scc;
}

//here question can be no of scc or print all the scc
//changes will be done as per question