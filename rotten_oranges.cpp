#include<iostream>
#include<queue>
using namespace std;

struct elem{
int x;
int y;
};

bool safe(int x,int y, int R,int C)
{
if(x>=0 && x<R && y>=0 && y<C)
return true;
return false;
}

void ro(int g[][5],int R,int C)
{
int cycle = 0;
int row[] = {0,-1,1,0};
int col[] = {-1,0,0,1};
queue<elem>q;

// push all rotten oranges 
for(int i=0;i<R;i++)
{
for(int j=0;j<C;j++)
{
if(g[i][j] == 2)//rotten
q.push(elem{i,j});
}
}
// push delim
q.push(elem{-1,-1});
while(!q.empty())
{
elem e = q.front();
if(e.x == -1 && e.y == -1)
{
q.pop();
if(q.empty())
break;
q.push(elem{-1,-1});
cycle++;
continue;
}
q.pop();
int x = e.x, y = e.y;
for(int i=0;i<4;i++)
{
if(safe(x+row[i],y+col[i],R,C) && g[x+row[i]][y+col[i]] == 1)// valid pos and fresh orange 
{
g[x+row[i]][y+col[i]] = 2;
cout<<"\nPushing: "<<x+row[i]<<" "<<y+col[i];
q.push(elem{x+row[i],y+col[i]});
}
}
}
cout<<"\nCyles: "<<cycle;
}
main()
{
int arr[][5] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
ro(arr,3,5);
}


