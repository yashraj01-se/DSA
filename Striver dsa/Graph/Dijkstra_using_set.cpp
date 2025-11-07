#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> Dijkstra(int V, vector<vector<int>> &edges, int src)
{

  // MAking Adj list:
  vector<vector<pair<int, int>>> adj(V);
  // UNDIRECTED Graph
    for (auto &e : edges)
    {
        int u = e[0], v = e[1], wt = e[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

  set<pair<int,int>>st;
  vector<int> dis(V,INT_MAX);
  dis[src] = 0;
  st.insert({0, src});

  while (!st.empty())
  {
    auto it = *(st.begin());
    int wt =it.first;
    int node=it.second;
    st.erase(it);

    for (auto it : adj[node]){
      int v=it.first;
      int weight=it.second;
      if(dis[node]+weight<dis[v]){
        dis[v]=dis[node]+weight;
        st.insert({dis[v],v});
      }
    }
  }
  return dis;
}
int main()
{
  vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 3}, {0, 2, 6}};
  int src = 2;
  int V = 3;

  vector<int> ans = Dijkstra(V, edges, src);
  for (auto it : ans)
  {
    cout << it << " ";
  }
}