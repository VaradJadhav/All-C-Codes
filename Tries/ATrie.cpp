#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    class node{
        public:
        bool end;
        node* next[26];
        node(){
            end=false;
            for(int i=0;i<26;i++){
                next[i]=NULL;
            }
        }
    };

    node* trie;
    Trie(){
        trie=new node();
    }

    void insert(string word){
        int i=0;
        node* it=trie;
        while(i<word.size()){
            if(it->next[word[i]-'a']==NULL)
                it->next[word[i]-'a']=new node();
            it=it->next[word[i]-'a'];
            i++;
        }
        it->end=true;
    }

    bool search(string word){
        int i=0;
        node* it=trie;
        while(i<word.size()){
            if(it->next[word[i]-'a']==NULL)
                return false;
            it=it->next[word[i]-'a'];
            i++;
        }
        return it->end;
    }
};

int main()
{
   Trie *myTrie=new Trie();
   vector<string> words={"varad","daasi"};
   for(auto w:words){
    myTrie->insert(w);
   }
   if(myTrie->search("sunil")){
    cout<<"Word exists";
   }else cout<<"Word not found";

    cout<<endl;
   if(myTrie->search("varad")){
    cout<<"Word exists";
   }else cout<<"Word not found";
   
   return 0;
}