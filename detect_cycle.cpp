#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;

class Graph{
int V;
list<int>*adj;

public:
Graph(int n)
{
V = n;
adj = new list<int>[V];
}

void addEdge(int src,int dest)
{
adj[src].push_back(dest);
}

void addEdge1(int src,int dest)
{
adj[src].push_back(dest);
adj[dest].push_back(src);
}

bool dir_cyc();
bool undir_cyc();
bool dir_cyc_util(int,vector<bool>,vector<bool>);
bool undir_cyc_util(int,vector<bool>,int);
};

bool Graph::dir_cyc()
{
vector<bool>visited(V,false);
vector<bool>rec(V,false);
for(int i=0;i<V;++i)
if(dir_cyc_util(i,visited,rec))
return true;
return false;
}

bool Graph::dir_cyc_util(int vertex,vector<bool>vis,vector<bool>rec)
{
if(!vis[vertex])
{
vis[vertex] = rec[vertex] = true;
list<int>::iterator ite;
for(ite=adj[vertex].begin(); ite!=adj[vertex].end(); ++ite)
{
if(!vis[*ite] && dir_cyc_util(*ite,vis,rec))
return true;
if(rec[*ite])
return true;
}
}
else
rec[vertex] = false;
return false;
}

//undirected
bool Graph::undir_cyc()
{
vector<bool>visited(V,false);
for(int i=0;i<V;++i)
if(undir_cyc_util(i,visited,-1))
return true;
return false;
}
bool Graph::undir_cyc_util(int vertex,vector<bool>vis,int parent)
{
vis[vertex] = true;
list<int>::iterator ite;
for(ite=adj[vertex].begin(); ite!=adj[vertex].end(); ++ite)
{
if(!vis[*ite] && undir_cyc_util(*ite,vis,vertex))
return true;
if(vis[*ite] && *ite!=parent)
return true;
}
return false;
}

main()
{
//directed
Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
if(g.dir_cyc())
cout<<"\nCyclic!";
else
cout<<"\nNot cyclic!";
//udirected
Graph g1(5);
    g1.addEdge1(1, 0);
    g1.addEdge1(0, 2);
    g1.addEdge1(2, 0);
    g1.addEdge1(0, 3);
    g1.addEdge1(3, 4);
Graph g2(3);
    g2.addEdge1(0, 1);
    g2.addEdge1(1, 2);
if(g2.undir_cyc())
cout<<"\nCycle!";
else
cout<<"\nNot cyclic!";
}
