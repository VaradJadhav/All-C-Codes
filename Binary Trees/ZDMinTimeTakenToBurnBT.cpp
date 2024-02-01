#include<bits/stdc++.h>
using namespace std;

//each sec neighbouring nodes get burned from a target

int find(map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&mp,BinaryTreeNode<int>*target){
    queue<BinaryTreeNode<int>*>q;
    q.push(target);
    map<BinaryTreeNode<int>*,int>vis;
    vis[target]=1;
    int maxi=0;
    while(!q.empty()){
        int sz=q.size();
        int fl=0;
        for(int i=0;i<sz;i++){
            auto node=q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                fl=1;
                vis[node->left]=1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right]){
                fl=1;
                vis[node->right]=1;
                q.push(node->right);
            }
            if(mp[node] && !vis[mp[node]]){
                fl=1;
                vis[mp[node]]=1;
                q.push(mp[node]);
            }
        }
        if(fl)maxi++;
    }
    return maxi;
}


int TimeToBurnTree(BinaryTreeNode<int>*root,int start){
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mp;
    BinayTreeNode<int>* target=bfsToMapParents(root,mp,start);
    int maxi=find(mp,target);
    return maxi;
}


int main()
{
   int t;
   cin>>t;
   
   return 0;
}