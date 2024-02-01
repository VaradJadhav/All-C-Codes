#include<bits/stdc++.h>
using namespace std;

//intution is to assume first root as a target node
//then mark parents of each node 
//after getting the perfect target do bfs like algo over it


void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track,TreeNode* target){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode *curr = que.front();
        que.pop();
        if(curr->left){
            parent_track[curr->left] = curr;
            que.push(curr->left);
        }
        if(curr->right){
            parent_track[curr->right] = curr;
            que.push(curr->right);
        }
    }
}

vector<int> distanceK(TreeNode* root,TreeNode* target,int K){
    unordered_map < TreeNode*, TreeNode* > parent_track ;
    markParents(root,parent_track,target);
    unordered_map<TreeNode*,bool> visited;
    queue<TreeNode*> que;
    que.push(target);
    visited[target]=true;
    int curr_level=0;
    while(!que.empty()){
        int size=que.size();
        if(curr_level++==K)break;
        for(int i=0;i<size;i++){
            TreeNode* current=que.front();que.pop();
            if(current->left && !visited[current->left]){
                que.push(current->left);
                visited[current->left]=true;
            }
            if(current->right && !visited[current->right]){
                que.push(current->right);
                visited[current->right]=true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                que.push(parent_track[current]);
                visited[parent_track[current]]=true;
            }
        }
    }
    vector<int> result;
    while(!que.empty()){
        result.push_back(que.front()->val);
        que.pop();
    }
    return result;
}


int main()
{
   int t;
   cin>>t;
   
   return 0;
}