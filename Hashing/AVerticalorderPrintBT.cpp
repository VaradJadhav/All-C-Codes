#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left,*right;
};
Node* NewNode(int key){
    Node* node=new Node;
    node->key=key;
    node->left=node->right=NULL;
    return node;
}

void getverticalOrder(Node* root,int hdis,map<int,vector<int>>&m){
    if(root==NULL)return;
    m[hdis].push_back(root->key);
    getverticalOrder(root->left,hdis-1,m);
    getverticalOrder(root->right,hdis+1,m);
}

int main()
{
   Node* root=NewNode(10);
   root->left=NewNode(7);
   root->right=NewNode(4);
   root->left->left=NewNode(3);
   root->left->right=NewNode(11);
   root->right->left=NewNode(14);
   root->right->right=NewNode(6);
   map<int,vector<int>> m;
   getverticalOrder(root,0ll,m);
   for(auto it:m){
    cout<<it.first<<" "<<accumulate(it.second.begin(),it.second.end(),0ll)<<endl;
   }
   return 0;
}