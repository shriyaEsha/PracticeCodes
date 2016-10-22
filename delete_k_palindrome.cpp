#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>
using namespace std;
int min(int a,int b)

{

    return a<b?a:b;

}

bool is_k_palin(string s,int k)

{

//Your code here

int i,j,n = s.length();

int t[n+1][n+1];
string b="";
for(i=n-1;i>=0;i--)
b+=s[i];
b[n] = '\0';

for(i=0;i<=n;i++)
t[i][i] = 0;

for(i=0;i<=n;i++)
t[0][i] = i;
for(i=0;i<=n;i++)
t[i][0] = i;

cout<<"\ns: "<<s<<" b: "<<b<<endl;
for(i=1;i<=n;i++)

{

    for(j=1;j<=n;j++)

    {

        if(s[i-1] == b[j-1])

        t[i][j] = 0;

        else

        t[i][j] = min(t[i-1][j],t[i][j-1])+1;

    }

}
for(i=0;i<=n;i++)
{
for(j=0;j<=n;j++)
cout<<t[i][j]<<" ";
cout<<endl;
}
return t[n][n]<=k;

}
main()
{
string s = "abcdc";
int k = 1;
if(is_k_palin(s,k))
cout<<"\nYess";
else
cout<<"\nNoo";
}
