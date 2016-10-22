#include<iostream>
#include<limits.h>
#include<string.h>
#define V 9
using namespace std;
char ch;
int min(int a,int b)
{
return a<b?a:b;
}
int dijkstra(int g[V][V],int s,int d,bool visited[],int min_dist)
{
int dist=0;
visited[s] = true;
if(s==d)
return 0;
for(int i=0;i<V;i++)
{
if(!visited[i] && g[s][i]!=0)
{
cout<<"\nSrc: "<<s<<" I: "<<i<<" dist: "<<g[s][i];
cin>>ch;
dist += g[s][i]+dijkstra(g,i,d,visited,min_dist);
if(dist<min_dist)
min_dist = dist;
else
visited[i] = false;
}
}
return dist;
}

main()
{
int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
int src = 0;
int dest = 8;
bool visited[V];
memset(visited,false,sizeof(V));
int min_dist = INT_MAX;
int cost = dijkstra(graph, src,dest,visited,min_dist);
cout<<cost;
}
