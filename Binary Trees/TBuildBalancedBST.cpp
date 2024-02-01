// 1]make middle element root
// 2]recursively,do the same for subtrees
//     a>start to mid-1
//     b>mid+1 to end


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

Node* sortedArrayToBST(int arr[],int st,int en){
    if(st>en)return NULL;
    int mid=(st+en)/2;
    Node* root=new Node(arr[mid]);
    root->left=sortedArrayToBST(arr,st,mid-1);
    root->right=sortedArrayToBST(arr,mid+1,en);
    return root;
}

void preorder(Node* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
   int arr[]={10,20,30,40,50};
   Node* root=sortedArrayToBST(arr,0,4);
   preorder(root);
   return 0;
}