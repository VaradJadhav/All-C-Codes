//1st level - print from left to right
//2nd level - print from right to left
//...likewise

//Use 2 stacks - currlevel and next level
//variable lefttoright boolean
//if lefttoright, push left child then right 
//else push right child then left


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

void ZigZagTraversal(Node* root){
    if(root==NULL)return;
    stack<Node*> currLevel,nextLevel;
    bool LeftToRight=1;
    currLevel.push(root);
    while(!currLevel.empty()){
        Node* temp=currLevel.top();
        currLevel.pop();
        if(temp){
            cout<<temp->data<<" ";
        if(LeftToRight){
            if(temp->left)nextLevel.push(temp->left);
            if(temp->right)nextLevel.push(temp->right);
        }else{
            if(temp->right)nextLevel.push(temp->right);           
            if(temp->left)nextLevel.push(temp->left);
        }
        }
        if(currLevel.empty()){
            LeftToRight = !LeftToRight;
            swap(currLevel,nextLevel);
        }
    }
}

int main()
{
   struct Node* root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    ZigZagTraversal(root);
   return 0;
}