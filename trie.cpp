/*  YV JAWAHAR TRIE
    Problem statement: Given some words insert into the trie and search for words given by the user
    if found return 1 else 0
*/
#include<bits/stdc++.h>
using namespace std;
class Trie
{
    Trie *children[26];
    bool endofWord;
    public:
     Trie *getNode(void)
    {
         Trie *pnode=new Trie;
           pnode->endofWord=false;
           for(int i=0;i<26;++i)
           {
              pnode->children[i]=NULL;
           }
           return pnode;
    }
    void insert(Trie *root,string s)
    {
           Trie*p=root;
           int n=s.length();
           for(int i=0;i<n;++i)
           {
            int k=s[i]-'a';
            if(!p->children[k])
               p->children[k]=getNode();
              p=p->children[k];
           }
           p->endofWord=true;
    }
    bool search(Trie*root,string search)
    {
        Trie*p=root;
        int n=search.length();
        for(int i=0;i<n;++i)
        {
                  int k=search[i]-'a';
                  if(p->children[k]==NULL)
                  {
                    return false;
                  }
                   p=p->children[k];
        }
        return (p!=NULL && p->endofWord);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    Trie x;
    Trie *root=x.getNode();
    x.insert(root,"ab");
    x.insert(root,"abc");
    x.insert(root,"abcde");
    cout<<x.search(root,"abc")<<endl;
    cout<<x.search(root,"ab")<<endl;
    cout<<x.search(root,"abcdefgh")<<endl;
}