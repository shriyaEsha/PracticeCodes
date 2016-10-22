#include<iostream>
#define M 8
#define N 8
using namespace std;
int rows[] = {-1,-1,-1,0,1,1,1,0};
int cols[] = {-1,0,1,1,1,0,-1,-1};
void ff(int g[M][N],int color,int new_color,int x,int y)
{
if(g[x][y]!=color)
return;
else if(g[x][y]==color)
g[x][y] = new_color;
for(int i=0;i<8;i++)
{
int nx = x+rows[i];
int ny = y+cols[i];
if(nx>=0 && nx<M && ny>=0 && ny<N)
ff(g,color,new_color,nx,ny);
}
}
main()
{
int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                     };
    int x = 4, y = 4, newC = 3;
for(int i=0;i<M;i++)
{
for(int j=0;j<N;j++)
cout<<screen[i][j]<<" ";
cout<<endl;
}
ff(screen,screen[x][y],newC,x,y);
cout<<endl;
for(int i=0;i<M;i++)
{
for(int j=0;j<N;j++)
cout<<screen[i][j]<<" ";
cout<<endl;
}
}
