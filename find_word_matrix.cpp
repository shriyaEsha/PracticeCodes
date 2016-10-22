#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

bool search_(char grid[][14],char word[],bool visited[][14],int x,int y,int curlen)
{
visited[x][y] = true;
if(curlen == strlen(word))
return true;
int rows[] = {-1,-1,-1,0,1,1,1,0};
int cols[] = {-1,0,1,1,1,0,-1,-1};
for(int i=0;i<8;i++)
{
int nextx = x+rows[i];
int nexty = y+cols[i];
if(nextx>=0 && nextx<14 && nexty>=0 && nexty<14 && !visited[nextx][nexty] && grid[nextx][nexty]==word[curlen])
return search_(grid,word,visited,nextx,nexty,curlen+1);
visited[x][y] = false;
}
return false;
}
void search(char grid[][14],char word[])
{
bool visited[3][14];
memset(visited,false,sizeof(visited));
for(int i=0;i<3;i++)
{
for(int j=0;j<14;j++)
if(grid[i][j] == word[0] && search_(grid,word,visited,i,j,1))
{
cout<<"\nPattern found!"<<i<<" "<<j;
}
}
}

main()
{
char grid[][14] = {"GEEKSFORGEEKS",
                    "GEEKSQUIZGEEK",
                    "IDEQAPRACTICE"};
char word[] = {"GEEKS"};
search(grid,word);
}
