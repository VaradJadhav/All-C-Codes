#include<bits/stdc++.h>
using namespace std;

//complete binary tree
//find no of nodes in less than O(n)

int findHeightLeft(TreeNode* node){
    int hght=0;
    while(node){
        hght++;
        node=node->left;
    }
    return hght;
}
int findHeightRight(TreeNode* node){
    int hght=0;
    while(node){
        hght++;
        node=node->right;
    }
    return hght;
}

int countNodes(TreeNode* root){
    if(!root) return 0;
    int lh=findHeightLeft(root);
    int rh=findHeightRight(root);
    if(lh==rh)return (1<<lh)-1;
    return 1+countNodes(root->left)+count(root->right);
}

// O(log2^2(n))
int main()
{
   int t;
   cin>>t;
   
   return 0;
}