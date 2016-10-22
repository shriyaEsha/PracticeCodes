#include<iostream>
#include<math.h>
#include<set>
using namespace std;

main()
{
int a[] = {1,2,3},n= sizeof(a)/sizeof(a[0]);
//power set
for(int i=0;i<pow(2,n);i++)
{
for(int j=0;j<n;j++)
{
if(i & (1<<j))
cout<<"["<<a[j]<<"] ";
}
cout<<endl;
}
//repeated elems
int b[]={1,2,2};
n = sizeof(b)/sizeof(b[0]);
set<int> s;
for(int i=0;i<n;i++)
s.insert(b[i]);
n = s.size();
set<int>::iterator ite;
int i;
for(ite = s.begin(),i=0;ite!=s.end();++ite,++i)
b[i] = *ite;
for(int i=0;i<pow(2,n);i++)
{
for(int j=0;j<n;j++)
{
if(i & (1<<j))
cout<<"["<<b[j]<<"] ";
}
cout<<endl;
}


}
