#include<iostream>
#include<string>
#include<string.h>
#include<ctype.h>
#define N 256
using namespace std;

void longest_string_wo_repeating(string s)
{
int i,start,n=s.length(),len=1,prev,vis[N],maxlen=0;
for(i=0;i<N;i++)
vis[i] = -1;
for(i=0;i<n;i++)
{
prev = vis[s[i]];
if(prev==-1 || i-len>=prev)  
{
len++;
}
else
{
if(len>maxlen)
maxlen = len;
//end
len = i-prev;
}
vis[s[i]] = i;
}
cout<<"\nLongest substring without duplicates: "<<maxlen;
cout<<"\nstart: "<<start-len;
}

main()
{
string s = "GEEKSFORGEEKS";
longest_string_wo_repeating(s);
}
