#include<iostream>
#include<queue>
using namespace std;

struct node{
int data;
node *left,*right,*nr;
};

node * create(int d)
{
node * t = new node;
t->data = d;
t->left = t->right = t->nr = NULL;
return t;
}

void level_order(node *root)
{
char ch;
queue<node*>q;
q.push(root);
node *nullnode = create(-1);
q.push(nullnode);

while(q.size()>1)
{
node * elem = q.front();
q.pop();
if(q.size()>0)
if(q.front() == nullnode)
{
elem->nr = NULL;
q.pop();
}
else
elem->nr = q.front();

if(elem->left)
q.push(elem->left);
if(elem->right)
q.push(elem->right);
q.push(nullnode);
}
}

int max(int a,int b)
{
return a>b?a:b;
}

int height(node *root)
{
if(!root)return 0;
return 1+max(height(root->left),height(root->right));
}


void disp_level(node *root,int level)
{
if(!root)return;
if(level==1)
cout<<root->data<<" ";
disp_level(root->left,level-1); 
disp_level(root->right,level-1); 
}

void disp_level_nr(node *root,int level)
{
if(!root)return;
if(level==1)
{
node * cur = root;
do
{cout<<root->data<<"-->";
if(cur->nr)
cur = cur->nr;
}while(cur->nr);
}
disp_level_nr(root->left,level-1); 
disp_level_nr(root->right,level-1); 
}

void disp(node *root)
{
int h = height(root)+1;
for(int i=1;i<=h;i++)
{
disp_level(root,i);
cout<<endl;
}
cout<<endl;
for(int i=1;i<=h;i++)
{
disp_level_nr(root,i);
cout<<endl;
}


}

main()
{
node *root = NULL;
root = create(12);
root->left = create(9);
root->right = create(30);
root->left->left = create(8);
root->left->right = create(10);
root->right->right = create(35);

disp(root);
level_order(root);
}
