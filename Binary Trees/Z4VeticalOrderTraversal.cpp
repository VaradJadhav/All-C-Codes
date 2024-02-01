#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> veticalTraversal(TreeNode* root){
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int,int>>> todo; //{node address,{vertical,level}}
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int x=p.second.first,y=p.second.second;
        nodes[x][y].insert(node->val);
        if(node->left)todo.push({node->left,{x-1,y+1}});
        if(node->right)todo.push({node->right,{x+1,y+1}});
    }
    vector<vector<int>> ans;
    for(auto it:nodes){
        vector<int> col;
        for(auto iit:it.second)col.insert(col.end(),iit.second.begin(),iit.second.end());
        ans.push_back(col);
    }
    return ans;
}

vector<int> topView(Node* root){
    vector<int> ans;
    if(!root)return ans;
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node* node=it.first;
        int line=it.second;
        if(mp.find(line)==mp.end())mp[line]=node->data;
        if(node->left)q.push({node->left,line-1});
        if(node->right)q.push({node->right,line+1});
    }
    for(auto it:mp)ans.push_back(it.second);
    return ans;
}
int main()
{
   int t;
   cin>>t;
   
   return 0;
}