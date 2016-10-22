#include<iostream>
#include<list>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
class Graph{
int V;
list<int>*adj;
public:
Graph(int v)
{
V = v;
adj = new list<int>[V];
}
void addEdge(int s,int d)
{
adj[s].push_back(d);
}

void bfs(int src)
{
list<int>q;
q.push_back(src);
bool *visited = new bool[V];
for(int i=0;i<V;i++) 
visited[i] = false;

visited[src] = true;
list<int>::iterator i;
while(!q.empty())
{
int vertex = q.front();
cout<<vertex<<" ";
q.pop_front();
for(i=adj[vertex].begin();i!=adj[vertex].end();++i)
{
if(!visited[*i])
{
visited[*i] = true;
q.push_back(*i);
}
}
}
}
void dfs_util(int src,bool *visited)
{
visited[src] = true;
cout<<src<<" ";
list<int>::iterator i;
for(i=adj[src].begin();i!=adj[src].end();++i)
{
if(!visited[*i])
dfs_util(*i,visited);
}
}
void dfs(int src)
{
list<int>q;
q.push_back(src);
bool *visited = new bool[V];
for(int i=0;i<V;i++)
visited[i] = false;

list<int>::iterator i;
dfs_util(src,visited);
}

void topoutil(int vertex,bool* visited,stack<int>&s)
{
visited[vertex] = true;
list<int>::iterator i;
for(i=adj[vertex].begin();i!=adj[vertex].end();++i)
{
if(!visited[*i])
topoutil(*i,visited,s);
}
s.push(vertex);
}

void toposort()
{
bool visited[V];
stack<int>s;
for(int i=0;i<V;i++)
visited[i] = false;
for(int i=0;i<V;i++)
if(!visited[i])
topoutil(i,visited,s);

while(!s.empty())
{
cout<<s.top()<<" ";
s.pop();
}
}
void mother_vertex()
{
bool visited[V];
int mother;
for(int i=0;i<V;i++)
visited[i] = false;
for(int i=0;i<V;i++)
{if(!visited[i])
{dfs_util(i,visited);
mother = i;
}
}
// check if all vertices can be visited from mother
for(int i=0;i<V;i++)
visited[i] = false;
dfs_util(mother,visited);
for(int i=0;i<V;i++)
{
if(!visited[i])
{
cout<<"\nNot mother!";
return;
}
}
cout<<"\n"<<mother<<" is the mother vertex!";
}
};

main()
{
Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
cout<<"\nBFS: ";
g.bfs(2);
cout<<"\nDFS: ";
g.dfs(2);
cout<<"\nToposort: ";
g.toposort();
cout<<"\nMother vertex: ";
g.mother_vertex();
}
