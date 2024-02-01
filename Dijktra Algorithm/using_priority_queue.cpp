//Dijkstra algorithm finds minimum cost path from src node to dest node
//fastest algo with set but this is with prority queue
#include<bits/stdc++.h>
using namespace std;
#define int long long
//we are using here min-heap concept 
//to implement min-heap we have to use priority queue
//adjacency list is given in matrix of two<To_node,weight>
vector<int> dijkstra(int V,vector<vector<int>> adj[],int Src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //this is how we declare min-heap in c++
    vector<int> dist(V);
    for(int i=0;i<V;i++) dist[i] = 1e9;
    dist[Src]=0;
    pq.push({0,Src});

    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it:adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];
            if(dis+edgeWeight<dist[adjNode]){
                dist[adjNode] = dis+edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }

    return dist;
}


//time complexity -> O(E*log(V))
//How?
// V * (pop vertex from min heap + no of edges on each vertex * push in min heap)
// V * (log(heap size) + ne * log(heap size))
// V * log(heap size) * (ne + 1)
// as   ne = V-1
// V * V * log(heap size)
// as    heap size can be hypothetically V*V at max
// V * V * log(V*V)
// ->V^2*log(V)
// as   E can be V^2
// -> E*log(V)

//queue is not preffered becoz unneccessary paths get explored again and again increasing time 
//ans will come right at the last but time factor is increasing in this case