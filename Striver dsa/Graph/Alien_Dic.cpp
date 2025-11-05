#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
vector<int> topolo_sort(int N, vector<vector<int>> &adj)
{
    // step 1: Making the Indegree vector:
    vector<int> indegree(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // step 2:Initialize the queue:
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // step 3: Toposort:
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return ans;
}
string Alien_dic(vector<string> &dict, int k)
{
    int N = dict.size();
    // Step : Making the directed Acyclic Graph by Comparing pairs...
    vector<vector<int>> adj(k);
    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());

        for (int ptr = 0; ptr < len; ptr++)
        {
            if (s1[ptr] != s2[ptr])
            {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a'); // To make edge between...
                break;
            }
        }
    }

    // Step: Returning the ans...
    vector<int> topo = topolo_sort(k, adj);
    string ans = "";
    for (auto it : topo)
    {
        ans = ans + char(it +'a'); // Add 'a' to convert back to character
    }
    return ans;
}
int main()
{
    int K = 4;
    int N = 4;
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    string ans = Alien_dic(dict, K);
    cout << ans;
    return 0;
}