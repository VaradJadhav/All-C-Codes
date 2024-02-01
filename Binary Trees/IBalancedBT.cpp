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

int height(Node* root){
    if(root==NULL)return 0;
    return max(height(root->left),height(root->right))+1;
}
//O(n)
bool isBalanced(Node* root){
    if(root==NULL)return true;
    if(!isBalanced(root->left) || !isBalanced(root->right))
        return false;

    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)>1)return false;
    return true;
}
//O(n*n)


bool isBalancedEfficient(Node* root,int* height){
    if(root==NULL)return true;
    int lh=0,rh=0;
    if(!isBalancedEfficient(root->left,&lh) || !isBalancedEfficient(root->right,&rh))
        return false;
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1)return true;
    return false;
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

    struct Node* root2=new Node(1);
    root2->left=new Node(2);
    root2->left->left=new Node(3);

    //         1
    //       /
    //     2
    //   /
    // 3


   if(isBalanced(root))cout<<"Balanced BT";
   else cout<<"Not Balanced";
   cout<<endl;
   if(isBalanced(root2))cout<<"Balanced BT";
   else cout<<"Not Balanced";

   cout<<endl;
   int height=0;
   if(isBalancedEfficient(root2,&height))cout<<"Balanced";
   else cout<<"Not balanced";
   return 0;
}