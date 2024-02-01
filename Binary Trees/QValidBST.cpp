//we have to check for
//max of left subtree
//min of right subtree

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

bool isBST(Node* root,Node* mini,Node* maxi){
    if(root==NULL)return true;
    if(mini!=NULL && root->data<=mini->data)return false;
    if(maxi!=NULL && root->data>=maxi->data)return false;
    bool leftvalid=isBST(root->left,mini,root);
    bool rightvalid=isBST(root->right,root,maxi);
    return leftvalid and rightvalid;
}

int main()
{
   struct Node* root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    struct Node* root2 = new Node(1);
   root2->left = new Node(0);
   root2->right = new Node(3);

    cout<<isBST(root,NULL,NULL);
    cout<<isBST(root2,NULL,NULL);
   return 0;
}