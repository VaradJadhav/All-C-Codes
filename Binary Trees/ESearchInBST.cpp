
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

Node* searchInBST(Node* root,int key){
    if(root==NULL)return NULL;
    if(root->data==key){
        return root;
    }
    if(root->data>key){
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}
int main()
{
   struct Node* root = new Node(3);
   root->left = new Node(1);
   root->right = new Node(5);
    root->left->left = new Node(0);
    root->left->right = new Node(2);
    root->right->left = new Node(4);
    root->right->right = new Node(7);
   if(searchInBST(root,5)==NULL){
    cout<<"Key does not exist";
   }else{
    cout<<"Key exists";
   }
   return 0;
}