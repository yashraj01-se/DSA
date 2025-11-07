#include <iostream>
#include <vector>
#include <queue>
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

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> dis(V,INT_MAX);
  dis[src] = 0;
  pq.push({0, src});

  while (!pq.empty())
  {
    int node = pq.top().second;
    int wt = pq.top().first;
    pq.pop();

    for (auto it : adj[node]){
      int v=it.first;
      int weight=it.second;
      if(dis[node]+weight<dis[v]){
        dis[v]=dis[node]+weight;
        pq.push({dis[v],v});
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