//we know that inorder of BST is increasing sequence

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

Node* ConstructBST(int preorder[],int* preorderIdx,int key,int mini,int maxi,int n){
    if(*preorderIdx>=n)return NULL;
    Node* root=NULL;
    if(key>mini && key<maxi){
        root=new Node(key);
        *preorderIdx=*preorderIdx+1;
        if(*preorderIdx<n){
            root->left=ConstructBST(preorder,preorderIdx,preorder[*preorderIdx],mini,key,n);
        }
        if(*preorderIdx<n){
            root->right=ConstructBST(preorder,preorderIdx,preorder[*preorderIdx],key,maxi,n);
        }
    }
    return root;
}

void Preorder(Node* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
int main()
{
   int preorder[]={10,2,1,13,11};
   int n=5;
   int preorderIdx=0;
   Node* root=ConstructBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
   Preorder(root);
   return 0;
}