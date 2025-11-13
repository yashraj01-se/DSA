#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int find_shortest_path(pair<int, int> &src, pair<int, int> &dest, vector<vector<int>> &grid)
{
    // Step 1: Initialization
    queue<pair<int, pair<int, int>>> q; //{dis,{row,col}}
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    dis[src.first][src.second] = 0;
    q.push({0, {src.first, src.second}});

    // Step 2: Direction
    int delrow[4] = {-1, 0, +1, 0};    // Similarly as for 4 direction we can do for 8 direction also
    int delcol[4] = {0, +1, 0, -1};

    // Edge Cases:
    if (grid[src.first][src.second] == 0)
        return -1;
    if (grid[dest.first][dest.second] == 0)
        return -1;
    if (src == dest)
        return 0;

    // Step 3: Dijistra algo
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int dist = it.first;
        int row = it.second.first;
        int col = it.second.second;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && dis[nrow][ncol] > dist + 1)
            {
                dis[nrow][ncol] = dist + 1;
                if (nrow == dest.first && ncol == dest.second)
                {
                    return dist + 1;
                }
                q.push({dist + 1, {nrow, ncol}});
            }
        }
    }

    return -1;
}
int main()
{
    pair<int, int> src = {0, 1};
    pair<int, int> dest = {2, 2};
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};
    int ans = find_shortest_path(src, dest, grid);
    cout << ans << endl;
    return 0;
}