#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

void swap(char &a,char&b)
{
char t = a;
a = b;
b = t;
}
// needed for qsort
int compare(const void *a,const void *b)
{
return *(char*)a-*(char*)b;
}

void perm(char *str,int start,int end)
{
if(start == end)
cout<<str<<endl;

for(int i = start;i<=end;i++)
{
swap(str[i],str[start]);
perm(str,start+1,end);
swap(str[i],str[start]);
}
}

int find_ceil(char *str,int lower,int upper,int n)
{
int ceil_idx = upper;
for(int i=upper;i<n;i++)
if(str[i]>str[lower] && str[i]<str[upper])
ceil_idx = i;
return ceil_idx;
}

void perm_dup(char *str,int n)
{
if(n == 1)
{
cout<<str;
return;
}
// sort string
qsort(str,n,sizeof(str[0]),compare);
bool finished = false;
while(!finished)
{
cout<<str<<endl;
// find first character smaller than the next from the end
int i;
for(i=n-2;i>=0;i--)
if(str[i]<str[i+1])
break;

if(i == -1)// no more perms
{
finished = true;
break;
}

// find ceil of first char
int sec_idx = find_ceil(str,i,i+1,n);
// swap ceil char with first
swap(str[sec_idx],str[i]);
// sort after first char
qsort(str+i+1,n-i-1,sizeof(str[0]),compare);
}
}

void count_freq(char *pat,int p[],int m)
{
for(int i=0;i<m;i++)
p[pat[i]]++;
}

bool compare_freq(int a[],int b[])
{
for(int i=0;i<256;i++)
if(a[i]!=b[i])
return false;
return true;
}

void anag_subs(char *text,char *pat,int m,int n)
{
int t[256],p[256];
memset(t,0,sizeof(t));
memset(p,0,sizeof(p));
count_freq(text,t,m);
count_freq(pat,p,m);
for(int i=m;i<n;i++)
{
if(compare_freq(t,p))
cout<<"\n anagram found at "<<i-m;
// add new character
t[text[i]]++;
//remove old character
t[text[i-m]]--;
}
if(compare_freq(t,p))
cout<<"\nanagram found at "<<n-m;
}

main()
{
char str[] = {"abca"};
char text[] = {"acbaabbabca"};
int n = strlen(str),m = strlen(text);
//perm(str,0,n-1);
//perm_dup(str,n);
//anag_subs(text,str,n,m);
	    string a;
	    getline(cin,a);
	   int i=0,j=0;
	    n = a.length();
	    while(j<n)
	    {
	        while(a[j]==' ')
	        {
	            j++;
	        }
	        if(a[j]!=' ' && j<n)
	        {
	            a[i++] = a[j++];
	        }
	    }
	    a[i] = '\0';
	    a.erase(a.begin()+i,a.end());
	    cout<<a<<endl;
}
