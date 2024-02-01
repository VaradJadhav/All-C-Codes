#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int calHeight(Node* root){
    if(root==NULL)return 0;
    int lHeight=calHeight(root->left);
    int rHeight=calHeight(root->right);
    return max(lHeight,rHeight)+1;
}
//O(n)
int calDiameter(Node* root){
    if(root==NULL)return 0;
    int lHeight=calHeight(root->left);
    int rHeight=calHeight(root->right);
    int currDiameter = lHeight+rHeight+1;

    int lDiameter = calDiameter(root->left);
    int rDiameter = calDiameter(root->right);
    return max(currDiameter,max(lDiameter,rDiameter));
}
//O(n*n)
int calDiameterEfficient(Node* root,int* height){
    if(root==NULL)return *height=0;
    int lh=0,rh=0;
    int lDiameter = calDiameterEfficient(root->left,&lh);
    int rDiameter = calDiameterEfficient(root->right,&rh);
    int currDiameter= lh+rh+1;
    *height = max(lh,rh)+1;
    return max(currDiameter,max(lDiameter,rDiameter));
}
//O(n)
int main()
{
   struct Node* root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   /*   
        1
       / \
      2   3

   */
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<calHeight(root)<<endl;//3
    cout<<calDiameter(root)<<endl;//3
   int height=0;
   cout<<calDiameterEfficient(root,&height);
   return 0;
}