#include<bits/stdc++.h>
using namespace std;


TreeNode* LowestCOmmonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL || root==p || root==q){
        return root;
    }
    TreeNode* left=LowestCOmmonAncestor(root->left,p,q);
    TreeNode* right=LowestCOmmonAncestor(root->right,p,q);
    if(left==NULL)return right;
    if(right==NULL)return left;
    return root;
}


int main()
{
   int t;
   cin>>t;
   
   return 0;
}