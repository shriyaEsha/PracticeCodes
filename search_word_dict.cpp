#include<iostream>
#include<string.h>
using namespace std;

char ch;

int x[] = {0,0,1,-1,-1,-1,1,1};
int y[] = {-1,1,0,0,-1,1,1,-1};
struct pos{
int row;
int col;
};

bool search_(char m[5][5],char str[],pos path[],int idx,bool visited[5][5],int row,int col)
{
cout<<"\nrow: "<<row<<" col: "<<col<<" idx: "<<idx;
cin>>ch;
if(idx == strlen(str))
return true;
for(int i=0;i<8;i++)
{
int nextx = x[i]+row;
int nexty = y[i]+col;
if(nextx>=0 && nextx<5 && nexty>=0 && nexty<5 && !visited[nextx][nexty] && m[nextx][nexty] == str[idx])
{
cout<<"\nNextx: "<<nextx<<" "<<"nexty: "<<nexty<<" Idx: "<<idx;
cin>>ch;
path[idx] = {nextx,nexty};
visited[nextx][nexty] = true;
if(search_(m,str,path,idx+1,visited,nextx,nexty))
return true;
visited[nextx][nexty] = false;
}
}
return false;
}

bool search(char m[5][5],char str[])
{
int n = 5;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(m[i][j]!=str[0])
continue;
// found start
pos path[strlen(str)];
bool visited[5][5];
for(int k=0;k<5;k++)
for(int l=0;l<5;l++)
visited[k][l] = false;

visited[i][j] = true;
path[0] = {i,j};
int idx = 1;
if(search_(m,str,path,idx,visited,i,j))
return true;
}
}
return false;
}


main()
{
char matrix[5][5] = { { 't', 'z', 'x', 'c', 'd' },
{ 'a', 'h', 'n', 'z', 'x' }, { 'h', 'w', 'o', 'i', 'o' },
{ 'o', 'r', 'n', 'r', 'n' }, { 'a', 'b', 'r', 'i', 'n' } };

char str[] = {"brown"};
int n = strlen(str),idx=0;
if(search(matrix,str))
cout<<"\nFound!";
else
cout<<"\nNot found!";
}
