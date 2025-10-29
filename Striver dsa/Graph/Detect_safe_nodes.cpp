// A safe node is one whose every node path ends at the terminal node.
// A terminal node is node which has zero outdegree.

/// Simple just remember that All the nodes that are the part of the cycle and nodes that lead to the cycle acn never be the safe nodes...
// apart from that all are safe nodes...

#include <iostream>
#include <vector>
using namespace std;
bool dfs(int node, vector<int> &vis, vector<int> &pathvis, vector<vector<int>>&graph, vector<int> &check)
{
    vis[node] = 1;
    pathvis[node] = 1;
    check[node] = 0;

    for (auto nei : graph[node])
    {
        if (!vis[nei])
        {
            if (dfs(nei, vis, pathvis, graph, check))
            {
                check[nei] = 0; /// Cycle detected ....
                return true;
            };
        }
        else if (pathvis[nei])
        {
            check[nei] = 0; // Cycle detected ....
            return true;
        }
    }

    check[node] = 1;
    pathvis[node] = 0;
    return false;
}
vector<int> findsafenodes(int V, vector<vector<int>>&graph)
{
    vector<int> vis(V, 0);
    vector<int> pathvis(V, 0);
    vector<int> Check(V, 0);
    vector<int> safenode;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, pathvis, graph, Check);
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (Check[i] == 1)
        {
            safenode.push_back(i);
        }
    }

    return safenode;
}
int main()
{
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {},{}}; // Directed Graph
    int V = graph.size();
    vector<int> ans = findsafenodes(V, graph);

   for(int i:ans){
    cout<<i<<" ";
   }
}