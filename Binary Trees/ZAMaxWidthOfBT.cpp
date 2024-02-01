#include<bits/stdc++.h>
using namespace std;


//width is no of nodes between any two nodes horizontally at a same level
//we have to count the node if it's not there also

//one intuiation is to give numbers to each node using 2*i+1 and 2*i+1 system for i'th node
//but it will get overflown for large trees

int widthOfBT(TreeNode* root){
    if(!root)return 0;
    int ans=0;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int mmin=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int cur_id=q.front().second-mmin;
            TreeNode* node=q.front().first;
            q.pop();
            if(i==0)first=cur_id;
            if(i==size-1)last=cur_id;
            if(node->left)q.push({node->left,cur_id*2+1});
            if(node->right)q.push({node->right,cur_id*2+2});
        }
        ans=max(ans,last-first+1);
    }
    return ans;
}


int main()
{
   int t;
   cin>>t;
   
   return 0;
}