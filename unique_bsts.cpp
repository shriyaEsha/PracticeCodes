#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
int data;
node *left,*right;
};

node *create(int d)
{
node * t = new node;
t->data = d;
t->left = t->right = NULL;
return t;
}
vector<node*> ub(int start,int end)
{
vector<node*>l;
if(start>end)
{
l.push_back(NULL);
return l;
}
for(int i=start;i<=end;i++)
{
vector<node*>left_tree = ub(start,i-1);
vector<node*>right_tree = ub(i+1,end);
for(int j=0;j<left_tree.size();j++)
{
node *left = left_tree[j];
for(int k=0;k<right_tree.size();k++)
{
node *right = right_tree[k];
node * root = create(i);
root->left = left;
root->right = right;
l.push_back(root);
}
}
}
return l;
}
void preorder(node *root)
{
if(!root)return;
cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);
}
main()
{
vector<node*>l = ub(1,3);
for(int i=0;i<l.size();i++)
{
preorder(l[i]);
cout<<endl;
}
}
