//if both empty return true
//else 
//a]check data at nodes is wqual
//b]check if left subtrees are same
//c]check if right subtrees are same
//if (a,b,c) are true return true else false


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

bool isIdentical(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)return true;
    if(root1==NULL || root2==NULL)return false;
    bool cond1=(root1->data==root2->data);
    bool cond2=isIdentical(root1->left,root2->left);
    bool cond3=isIdentical(root1->right,root2->right);
    if(cond1 && cond2 && cond3)return true;
    return false;
}

int main()
{
   struct Node* root1 = new Node(2);
   root1->left = new Node(1);
   root1->right = new Node(3);
   
   struct Node* root2 = new Node(2);
   root2->left = new Node(1);
   root2->right = new Node(4);
    cout<<isIdentical(root2,root1);
   return 0;
}