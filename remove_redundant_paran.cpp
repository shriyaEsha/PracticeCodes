#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<ctype.h>
using namespace std;
struct elem{
int left_pa;
char left_op;
char min_op;
};
int min(int a,int b)
{
return a<b?a:b;
}
int priority(char a)
{
switch(a)
{
case '+':
case '-': return 1;
case '*':
case '/':return 2;
case '#':return -1;
default:return -1;
}
}
bool opr(char a)
{
switch(a)
{
case '+':
case '-':
case '*':
case '/': return true;
default:return false;
}
}
bool opd(char a)
{
return isalpha(a);
}
void print_stack(stack<elem>s)
{
while(!s.empty())
{
elem e = s.top();
s.pop();
cout<<e.left_pa<<" "<<e.left_op<<" "<<e.min_op<<endl;
}
}
void remove(string a)
{
int n = a.length();
int i = 0;
stack<elem>s;
vector<pair<int,int> >result;

while(i<n)
{
int flag = 0;
cout<<"\ni: "<<i<<" a[i]: "<<a[i];
elem e;
while(a[i]=='(' && !opd(a[i+1]))
{
e.left_pa = i;
e.left_op = ' ';
e.min_op = ' ';
s.push(e);
flag = 1;
i++;
}
if(flag)
{
//last (
e.left_pa = i;
e.min_op = ' ';
e.left_op = ' ';
i++;
}
if(opd(a[i]))
i++;
if(opr(a[i]))
{
if(e.left_op== ' ')//empty
{
e.left_op = a[i];
e.min_op = a[i];
}
else//update min_op
e.min_op = min(priority(a[i]),s.top().min_op);
s.push(e);
i++;
}
if(a[i]==')')//idx 6,10
{
int saved_idx = i;
elem new_elem = s.top();//idx 2,0
s.pop();
while((i+1)<n && a[i+1]==')') //)
{
elem red = s.top();
s.pop();
i++;//7
cout<<"\nRedundant at : "<<red.left_pa<<" "<<i;
}
if(i==n-1)
{
if(new_elem.left_pa!=' ')
{cout<<"\nRedundant at: "<<new_elem.left_pa<<" "<<i;
return;
}
}
// check if this paranthesis is necessary
if((i+1)<n && opr(a[i+1]))
{
i++;//idx 8
// check priority with popped element
if(priority(a[i])<=priority(new_elem.min_op))
{
cout<<"\nRedundant att : "<<new_elem.left_pa<<" "<<saved_idx;
}
}
i++;
}

}
}
/*
vector<pair<int,int>>::iterator ite;
for(ite = result.begin();ite!=result.end();++ite)
cout<<(*ite)->first<<","<<(*ite)->second<<endl;
*/
main()
{
string a = "(((a-b))*d*(c-d))";
remove(a);
}
