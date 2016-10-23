#include<iostream>
#include<string>
using namespace std;

int max(int a,int b)
{
return a>b?a:b;
}

int four_as(int n)
{
if(n<=6)
return n;

int t[n+1];
for(int i=0;i<=6;i++)
t[i] = i;

for(int N=7;N<=n;N++)
{
t[N] = -1;
for(int b=N-3;b>=1;b--)
t[N] = max(t[N],t[b]*(N-b-1));
}
return t[n];
}

main()
{
cout<<four_as(11);
}
