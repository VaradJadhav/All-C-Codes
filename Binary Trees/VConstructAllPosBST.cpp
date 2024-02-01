
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

vector<Node*> constructTrees(int st,int en){
    vector<Node*> trees;
    if(st>en){
        trees.push_back(NULL);
    }
    for(int i=st;i<=en;i++){
        vector<Node*> leftSubtrees = constructTrees(st,i-1);
        vector<Node*> rightSubtrees = constructTrees(i+1,en);

        for(int j=0;j<leftSubtrees.size();j++){
            Node* left = leftSubtrees[j];
            for(int k=0;k<rightSubtrees.size();k++){
                Node* right = rightSubtrees[k];
                Node* node = new Node(i);
                node->left=left;
                node->right=right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preorder(Node* node){
    if(node==NULL)return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
   vector<Node*> totalTrees=constructTrees(1,4);
   for(int i=0;i<totalTrees.size();i++){
    cout<<(i+1)<<endl;
    preorder(totalTrees[i]);
    cout<<endl;
   }
   return 0;
}