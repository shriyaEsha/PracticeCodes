#include<iostream>
#include<queue>
#include<map>
#include<list>
#include<stdlib.h>
#include<limits.h>
using namespace std;
struct node{
int data;
node *left,*right;
};
int min(int a,int b)
{
return a<b?a:b;
}
int max(int a,int b)
{
return a>b?a:b;
}
void swap(int &a,int &b)
{
int t = a;
a = b;
b = t;
}

node *create(int d)
{
node *t = new node;
t->data = d;
t->left = t->right = NULL;
return t;
}

int height(node *root)
{
if(!root)return 0;
int l = height(root->left);
int r = height(root->right);
return l>r?l+1:r+1;
}

void disp_lev(node *root,int l)
{
if(!root)return;
if(l==1)
cout<<root->data<<" ";
disp_lev(root->left,l-1);
disp_lev(root->right,l-1);
}

void disp(node *root)
{
int h = height(root)+1;
for(int i=1;i<=h;i++)
{
disp_lev(root,i);
cout<<endl;
}
}

node *min_(node *root)
{
if(!root)return NULL;
if(!root->left) return root;
min_(root->left);
}

node *insert(node *root,int d)
{
if(!root)
{
root = create(d);
return root;
}
if(d<root->data)
root->left = insert(root->left,d);
else if(d>root->data)
root->right = insert(root->right,d);
return root;
}

node *del(node *root,int d)
{
if(!root)return NULL;
if(d<root->data)
root->left = del(root->left,d);
else if(d>root->data)
root->right = del(root->right,d);
else if(!root->left && !root->right)
{
node * temp = root;
root = NULL;
delete(temp);
return root;
}
else
{
if(!root->left)
{
node *temp = root;
root = root->right;
delete(temp);
return root;
}
else if(!root->right)
{
node *temp = root;
root = root->left;
delete(temp);
return root;
}
else
{
// find min of right 
node * temp = min_(root->right);
root-> data = temp->data;
root->right = del(root->right,temp->data);
}
}
return root;
}
void inorder(node *root)
{
if(!root)return;
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}

void preorder(node *root)
{
if(!root)return;
cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);
}

void postorder(node *root)
{
if(!root)return;
postorder(root->left);
postorder(root->right);
cout<<root->data<<" ";
}
void vo_util(node *root,int hd,int &min,int &max)
{
if(!root)return;
if(hd<min) min = hd;
if(hd>max) max = hd;
vo_util(root->left,hd-1,min,max);
vo_util(root->right,hd+1,min,max);
}
void print_vo(node *root,int hd,int line)
{
if(!root)return;
if(hd==line)
cout<<root->data<<" ";
print_vo(root->left,hd-1,line);
print_vo(root->right,hd+1,line);
}
void vert_order(node *root)
{
if(!root)return;
int min=-1,max=-1,hd=0;
vo_util(root,hd,min,max);
for(int i=min;i<=max;i++)
{
print_vo(root,0,i);
cout<<endl;
}
}
int min_height(node *root)
{
if(!root)return -1;
if(!root->left && !root->right)
return 1;
return min(min_height(root->left),min_height(root->right))+1;
}

//VIEWS
// top view - print only the first elem of each level OR print first elem of each hd value in VO_traversal - use map to store each hd value of elem and queue for level order trav
// bottom view - print the last elem of each hd value in VO_trav
// left and right views - print first elem of level order trav

// Binary tree to circular dll
// left subtree
// right subtree
// make root point to itself
// concat(concat(left,root),right) 
node *concat(node *first,node*last)
{
if(!first)return last;
if(!last)return first;
node *last_first = first->left;
node *last_last = last->left;
last_first->right = last;
last->left = last_first;
first->left = last_last;
last_last->right = first;
return first;
}
node *bt_cdll(node *root)
{
if(!root)return NULL;
node * left = bt_cdll(root->left);
node * right = bt_cdll(root->right);
root->left = root->right = root;
return concat(concat(left,root),right);
}
void disp_cdll(node *root)
{
if(!root)return;
node * rider = root;
do{
cout<<rider->data<<" ";
rider = rider->right;
}while(rider!=root);
}

// bt to dll
// inorder trav of bt 
// save prev so you can link to it
node *bt_dll(node *root, node **head)
{
if(!root)return NULL;
node * prev = NULL;
bt_dll(root->left,head);
if(!prev)
* head = root;
else
{
root->left = prev;
prev->right = root;
}
prev = root;
bt_dll(root->right,head);
}

// check if 2 trees are identical
// if data not same return false
// check for left and right subtrees
bool identical(node *root1,node *root2)
{
if(!root1 && !root2) return true;
else if(!root1 || !root2) return false;
return (root1->data == root2->data && identical(root1->left,root2->left)&&identical(root1->right,root2->right));
}

// print cousins of node and NOT siblings
// get level of node
// if level==2 ( children of root ) return
// else recurse for left and right subtrees reducing level by 1
int get_level(node *root,int data,int level)
{
if(!root)return 0;
if(root->data == data)
return level;
int l = get_level(root->left,data,level+1);
if(l>0)
return l;
get_level(root->right,data,level+1);
}
void cousins_util(node *root,int data,int level)
{
if(level<2)//root
return;
else if(level==2)//children of root
{
if(root->left->data == data || root->right->data == data)
return;
if(root->left)
cout<<root->left->data<<" ";
if(root->right)
cout<<root->right->data<<" ";
}
else if(level>2)
{
cousins_util(root->left,data,level-1);
cousins_util(root->right,data,level-1);
}
}
void cousins(node *root,int data)
{
if(!root)return;
int level = get_level(root,data,1);
cousins_util(root,data,level);
}
// check if 2 trees are subtrees
// store inorder and preorder trav of the two trees separately
// check if they're substrings of each other one by one
void mirror(node *root)
{
if(!root)return;
swap(root->left,root->right);
mirror(root->left);
mirror(root->right);
}
void print_path(int a[],int len)
{
for(int i=0;i<=len;i++)
cout<<a[i]<<" ";
cout<<endl;
}
void root_to_leaf(node *root,int a[],int pathlen)
{
if(!root)return;
a[pathlen] = root->data;
if(!root->left && !root->right)
{
print_path(a,pathlen);
}
root_to_leaf(root->left,a,pathlen+1);
root_to_leaf(root->right,a,pathlen+1);
}
void closest_node(node *root,int elem,int &diff,int &closest)
{
if(!root)return;
if(abs(root->data-elem)<diff)
{
diff = abs(root->data-elem);
closest = root->data;
}
if(elem<root->data)
closest_node(root->left,elem,diff,closest);
else if(elem>root->data)
closest_node(root->right,elem,diff,closest);
}

void left_bd(node *root)
{
if(!root)return;
if(root->left)
{
cout<<root->data<<" ";
left_bd(root->left);
}
else if(root->right)
{
cout<<root->data<<" ";
left_bd(root->right);
}
}
void right_bd(node *root)
{
if(!root)return;
if(root->right)
{
right_bd(root->right);
cout<<root->data<<" ";
}
else if(root->left)
{
right_bd(root->left);
cout<<root->data<<" ";
}
}
void leaf_bd(node *root)
{
if(!root)return;
leaf_bd(root->left);
if(!root->left && !root->right)
cout<<root->data<<" ";
leaf_bd(root->right);
}
void bd_traversal(node *root)
{
if(!root)return;
cout<<root->data<<" ";
if(root->left)
left_bd(root->left);
leaf_bd(root->left);
leaf_bd(root->right);
if(root->right)
right_bd(root->right);
}
void reverse_level_disp(node *root)
{
if(!root)return;
int h = height(root)+1;
for(int i=h;i>=1;i--)
{
disp_lev(root,i);
cout<<endl;
}
}
int count_nodes(node *root)
{
if(!root)return 0;
int l = count_nodes(root->left);
int r = count_nodes(root->right);
return l+r+1;
}
bool has_path_sum(node *root,int sum)
{
if(!root)return sum==0;
sum = sum-root->data;
if(sum==0 && !root->left && !root->right) return true;
if(root->left)
return has_path_sum(root->left,sum);
if(root->right)
return  has_path_sum(root->right,sum);
}
int sum_kids(node *root)
{
if(!root)return 0;
if(!root->left || !root->right)return root->data;
int summ = sum_kids(root->left)+sum_kids(root->right);
if(summ>root->data)
root->data = summ;
else
{
if(root->left)
root->left->data += root->data - summ;
else
root->right->data += root->data - summ;
}
return root->data;
}

main()
{
node * root = NULL;
int arr[] = {50,30,20,40,70,60,80},n = sizeof(arr)/sizeof(arr[0]);
for(int i=0;i<n;i++)
root = insert(root,arr[i]);
//disp(root);
//vert_order(root);
//node * cdll_root = bt_cdll(root);
//disp_cdll(cdll_root);
//cousins(root,20);
//mirror(root);
//disp(root);
int a[n];
//root_to_leaf(root,a,0);
int diff = INT_MAX,elem = 29,closest;
//closest_node(root,elem,diff,closest);
//cout<<"\nClosest: "<<closest;
//bd_traversal(root);
//reverse_level_disp(root);
//cout<<count_nodes(root->left);
/*if(has_path_sum(root,10))
cout<<"\nHas Path sum!";
else
cout<<"\nNo path sum";
*/
root = NULL;
root = create(8);
root->left = create(4);
root->right = create(2);
root->left->left = create(1);
root->left->right = create(1);
root->right->left = create(2);
root->right->right = create(4);
disp(root);
sum_kids(root);
disp(root);
}
