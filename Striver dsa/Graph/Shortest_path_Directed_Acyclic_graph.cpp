#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void toposort(int node, vector<int> &vis, stack<int> &st, vector<vector<pair<int, int>>> &adj)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        int v = it.first;
        if (!vis[v])
        {
            toposort(v, vis, st, adj);
        }
    }
    st.push(node);
}
vector<int> Find_shortest_path_DAG(int V, int edges, vector<vector<int>> &graph, int src)
{

    // Step 1: Prepare the adjaceny list:
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < edges; i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];
        int wt = graph[i][2];

        adj[u].push_back({v, wt});
    }

    // Step 2: Do the Topo sort using DFSor BFS we will do using DFS:
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            toposort(i, vis, st, adj);
        }
    }

    // Step 3: Do the distance thing:
    vector<int> dis(V);
    for (int i = 0; i < V; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dis[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if (dis[node] + wt < dis[v])
                {
                    dis[v] = dis[node] + wt;
                }
            }
        }
        else
        {
            dis[node] = -1;
        }
    }
    return dis;
}
int main()
{
    vector<vector<int>> graph = {
        {0, 1, 2}, // Edge from node 0 to 1 with weight 2
        {0, 2, 4}, // Edge from node 0 to 2 with weight 4
        {1, 3, 7}, // Edge from node 1 to 3 with weight 7
        {2, 3, 1}  // Edge from node 2 to 3 with weight 1
    }; // Directed Acyclic Graph with weights

    int V = 4;      // Number of vertices
    int source = 0; // Source node
    int edges = graph.size();
    vector<int> dis = Find_shortest_path_DAG(V, edges, graph, source);
    for (int i = 0; i < dis.size(); i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}