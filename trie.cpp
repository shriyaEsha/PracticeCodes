#include<iostream>
#define N 26
using namespace std;

struct node{
node *kids[N];
bool isLeaf;
};

node *create()
{
node *t = new node;
for(int i=0;i<N;i++)
t->kids[i] = NULL;
t->isLeaf = false;
}

node* insert(node *root,string s)
{
if(!root)
{
root = create();
}
node *crawl = root;
for(int i=0;i<s.length();++i)
{
int idx = int(s[i]-'a');
if(!crawl->kids[idx])
crawl->kids[idx] = create();
crawl = crawl->kids[idx];
}
crawl->isLeaf = true;
return root;
}

bool search(node *root,string s)
{
if(!root)return false;
node *crawl = root;
for(int i=0;i<s.length();++i)
{
int idx = int(s[i]-'a');
if(!crawl->kids[idx])
return false;
crawl = crawl->kids[idx];
}
//prefix
return crawl;
//whole word
return (crawl && crawl->isLeaf);
}

main()
{
node * root = NULL;
string s[] = {"hello","hey","how","hi"};
int n = 4;
for(int i=0;i<n;i++)
root = insert(root,s[i]);

string word = "he";
if(search(root,word))
cout<<"\nFound!";
else
cout<<"\nNot found!";
}
