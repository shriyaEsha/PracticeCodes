#include<iostream>
using namespace std;

struct node{
int data;
node *next,*down;
};

node *create(int data)
{
node * t = new node;
t->data = data;
t->next = NULL;
t->down = NULL;
return t;
}

node* insert(node *head,int data)
{
if(!head)
{
head = create(data);
return head;
}
node * t = create(data);
t->next = head;
head = t;
return head;
}

void disp(node *head)
{
if(!head)return;
while(head)
{
cout<<head->data<<"->";
head = head->next;
}
}

node* del(node *head)
{
if(!head)return NULL;
node * t = head;
delete(t);
head = head->next;
head = del(head);
delete(head);
return NULL;
}
node *reverse(node *head)
{
char ch;
if(!head)return NULL;
node *prev = NULL,*r,*q = head;
while(q)
{
r = q;
q = q->next;
r->next = prev;
prev = r;
}
return r;
}
node* rev_rec(node *head)
{
if(!head)return NULL;
if(!head->next)return head;
node *secondList = rev_rec(head->next);
head->next->next = head;
head->next = NULL;
return secondList;
}
void nth_from_end(node *head,int n)
{
if(!head)return;
nth_from_end(head->next,n);
static int i = 0;
if(++i==n)
cout<<head->data;
}
bool check_pal(node *head,node**saved)
{
if(!head)return true;
if(!check_pal(head->next,saved))
return false;
if(head->data == (*saved)->data)
{
*saved = (*saved)->next;
return true;
}
}

main()
{
node * head = NULL;
int a[] = {5,2,3,2,3},n = sizeof(a)/sizeof(a[0]);
for(int i=0;i<n;i++)
head = insert(head,a[i]);
disp(head);
cout<<endl;
head = rev_rec(head);
disp(head);
cout<<endl;
//nth_from_end(head,3);
//del(head);
if(check_pal(head,&head))
cout<<"\nPal!";
else
cout<<"\nNot pal!";
}
