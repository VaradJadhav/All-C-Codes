#include<bits/stdc++.h>
using namespace std;
//multiple source shortest path
//helps you detect -ve cycles as well
//use of adjacency matrix 

void shortest_distance(vector<vector<int>> &matrix){
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==-1)matrix[i][j]=1e9;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(matrix[i][i]<0){
            //-ve edge cycle
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1e9)matrix[i][j]=-1;
        }
    }
}