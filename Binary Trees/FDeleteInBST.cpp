
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

//Case 1: deleting leaf node - direct delete
//Case 2: node has one child - replace node with the child & delete the node
//Case 3: node has 2 children - 1]find inorder successor of the node
//                              2]replace  node with inorder successor
//                              3]delete the node

//BST ka inorder sequence is nothing but sorted sequence

Node* inorderSucc(Node* root){
    Node* curr=root;
    while(curr && curr->left != NULL){
        curr=curr->left;
    }
    return curr;
}

Node* deleteInBST(Node* root,int key){
    if(key<root->data){
        root->left=deleteInBST(root->left,key);
    }
    if(key>root->data){
        root->right=deleteInBST(root->right,key);
    }
    if(key==root->data){
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=deleteInBST(root->right,temp->data);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
   struct Node* root = new Node(3);
   root->left = new Node(1);
   root->right = new Node(5);
   root->left->left = new Node(0);
   root->left->right = new Node(2);
   root->right->left = new Node(4);
   root->right->right = new Node(6);
   inorder(root);
   cout<<endl;
   root = deleteInBST(root,5);
   inorder(root);
   cout<<endl;
   root = deleteInBST(root,1);
   inorder(root);
   cout<<endl;
   return 0;
}