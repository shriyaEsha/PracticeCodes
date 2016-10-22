#include<iostream>
#include<string>
using namespace std;

bool isMatch(char *s,char *p)
{
if(*s == '\0' && *p == '\0')
return true;

if(*s=='\0' && *(p+1) == '*')
return isMatch(s,p+2);

if(*s=='\0' || *p=='\0')
return false;

if(*(p+1) == '*')
{
bool a = isMatch(s,p+2);
bool b = false;
if(*s == *p || *p=='.')
b = isMatch(s+1,p);
return a||b;
}

if(*s == *p || *p == '.') 
return isMatch(s+1,p+1);

if(*p == '*')
return isMatch(s+1,p)||isMatch(s,p+1);

return false;
}

main()
{
char *s=new char[256],*p=new char[256];
while(1)
{
cin>>s>>p;
cout<<bool(isMatch(s,p))<<endl;
}
}

