#include<iostream>
#include<string.h>
#include<limits.h>
#define V 9
using namespace std;

int max(int a,int b)
{
return a>b?a:b;
}

int cut_rod(int len,int price[],int dp[])
{
if(len<=0)return 0;
if(dp[len]!=-1)
return dp[len];
int cost = INT_MIN;
for(int i=1;i<=len;++i)
cost = max(cost,price[i-1]+cut_rod(len-i,price,dp));
return cost;
}

int path(int g[V][V],int s,int d,bool visited[],int min_path)
{
if(s==d)return 0;
int dd = INT_MAX;
visited[s] = true;
for(int i=0;i<V;i++)
{
if(!visited[i] && g[s][i])
dd = min(d,g[s][i]+path(g,i,d,visited,min_path));
if(dd<min_path)
min_path = dd;
visited[i] = false;
}
return min_path;
}



main()
{
int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
int len = sizeof(price)/sizeof(price[0]);
int dp[len+1];
memset(dp,-1,sizeof(dp));
dp[0] = 0;
//cout<<cut_rod(len,price,dp);
bool vis[V];
memset(vis,0,sizeof(vis));
int g[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
cout<<path(g,0,8,vis,INT_MAX);
}
