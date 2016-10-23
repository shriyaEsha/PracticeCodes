#include<iostream>
#include<string>
#include<string.h>
#include<limits.h>
using namespace std;
// min cuts to make pal
void pal_part(string a)
{
int n = a.length();
bool c[n][n];
int t[n][n];

memset(c,false,sizeof(c));
memset(t,0,sizeof(t));


for(int i=0;i<n;i++)
{
c[i][i] = true;
t[i][i] = 0;
}

for(int l=2;l<=n;l++)
{
for(int i=0;i<n-l+1;i++)
{
int j = i+l-1;
if(a[i] == a[j] && l==2)
c[i][j] = true;
else if(l>2 && a[i]==a[j] && c[i+1][j-1])
c[i][j] = true;
if(c[i][j])
t[i][j] = 0;
else
{
t[i][j] = INT_MAX;
for(int k=i;k<j;k++)
{
int p = t[i][k] + t[k+1][j]+1;
if(p<t[i][j])
t[i][j] = p;
}
}
}
}
cout<<"\nMin cuts to make into palindrome: "<<t[0][n-1];
}

//longest pal substring
void longest_pal_substring(string a)
{
int n=a.length();
int start,maxlen;
bool c[n][n];

for(int i=0;i<n;i++)
c[i][i] = true;

for(int i=0;i<n-1;i++)
{
if(a[i]==a[i+1])
{
c[i][i+1] = true;
maxlen = 2;
start = i;
}
}

for(int l=3;l<=n;l++)
{
for(int i=0;i<n-l+1;i++)
{
int j = i+l-1;
if(a[i]==a[j] && c[i+1][j-1])
{
c[i][j] = true;
if(l>maxlen)
{
maxlen = l;
start = i;
}
}
}
}

cout<<"\nMaxlen: "<<maxlen<<endl;
for(int i=start;i<start+maxlen;i++)
cout<<a[i];
}

main()
{
string a = "forgeeksskeegro";
pal_part(a);
longest_pal_substring(a);
}
