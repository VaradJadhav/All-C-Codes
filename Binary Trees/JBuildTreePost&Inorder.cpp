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

//1]start from end of postorder & pick a ele to 
//create a node
//2]decrement postorder idx
//3]search pos of picked in inorder
//4]call build right subtree from inorder's pos+1 to n
//5]call build left subtree from inorder's 0 to pos-1
//return node

int search(int inorder[],int st,int en,int val){
    for(int i=st;i<=en;i++){
        if(inorder[i]==val)
            return i;
    }
    return -1;
}

Node* buildTree(int postorder[],int inorder[],int st,int en){
    static int idx = 4;
    if(st>en)return NULL;
    int val = postorder[idx];
    idx--;
    Node* curr = new Node(val);
    if(st==en){
        return curr;
    }
    int pos = search(inorder,st,en,val);
    curr->right = buildTree(postorder,inorder,pos+1,en);
    curr->left = buildTree(postorder,inorder,st,pos-1);
    return curr;
}

void InorderPrint(Node* root){
    if(root==NULL)return;
    InorderPrint(root->left);
    cout<<root->data<<endl;
    InorderPrint(root->right);
}

int main()
{
   int postorder[]={4,2,5,3,1};
   int inorder[]={4,2,1,5,3};
   Node* root = buildTree(postorder,inorder,0,4);
   InorderPrint(root);
   return 0;
}