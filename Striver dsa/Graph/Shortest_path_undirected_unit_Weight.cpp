#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> Shortest_path_undirected_unit_Weight(int n, vector<vector<int>> &adj, int src)
{
    vector<int> dis(n, INT_MAX);
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;

    while (!q.empty())
    {
        int node = q.front().first;
        int wt = q.front().second;
        q.pop();

        for (auto it : adj[node])
        {
            int v = it;
            if (dis[node] + 1 < dis[v])
            {
                dis[v] = dis[node] + 1;
                q.push({v, dis[v]});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dis[i] == INT_MAX)
        {
            dis[i] = -1;
        }
    }
    return dis;
}
int main()
{
    vector<vector<int>> adj = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2, 4},
        {3}};
    int src = 0;
    int n = adj.size();
    vector<int> ans = Shortest_path_undirected_unit_Weight(n, adj, src);

    for(auto it:ans){
        cout<<it<<" ";
    }
}