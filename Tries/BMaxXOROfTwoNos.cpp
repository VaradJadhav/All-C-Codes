//find maximum xor of two numbers in an array

//write all nos in binary
//make a trie such that 0 is on left and 1 on right

//at last we have to take the alternate left and right 
//to get maximum xor

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode *next[2];
    TrieNode(){
        next[0]=NULL;
        next[1]=NULL;
    }
};

TrieNode* buildtrie(vector<int> &a){
    TrieNode *root=new TrieNode();
    int n=a.size();
    for(int i=0;i<n;i++){
        int num=a[i];
        TrieNode *curr=root;
        for(int j=31;j>=0;j--){
            int bit=(num>>j)&1;
            if(curr->next[bit]==NULL)
                curr->next[bit]=new TrieNode();
            curr=curr->next[bit];
        }

    }
    return root;
}

int helper(TrieNode *root,vector<int> &a){
    int res=0;
    for(int i=0;i<a.size();i++){
        int num=a[i];
        TrieNode *it=root;
        int cur_max=0;
        for(int j=31;j>=0;j--){
            int bit=((num>>j)&1)?0:1;
            if(it->next[bit]){
                cur_max<<=1;
                cur_max |= 1;
                it=it->next[bit];
            }else{
                cur_max<<=1;
                cur_max |= 0;
                it=it->next[bit xor 1];
            }
        }
        res=max(res,cur_max);
    }
    return res;

}

int main()
{
   int t;
   cin>>t;
   vector<int> v(t);
   for(int i=0;i<t;i++)cin>>v[i];
   TrieNode *root=buildtrie(v);
   int ans=helper(root,v);
   cout<<ans<<endl;
   return 0;
}