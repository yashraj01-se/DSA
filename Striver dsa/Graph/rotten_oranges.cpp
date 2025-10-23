#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    vector<vector<int>> grid = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}};
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Step 1:Find the rooten oranges and Place them into the queue:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2 && vis[i][j] != 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else
            {
                vis[i][j] = 0;
            }
        }
    }

    // step 2: Finding the Time:

    int delrow[4] = {-1, 0, +1, 0};
    int delcol[4] = {0, +1, 0, -1};
    int tm = 0;

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        q.pop();
        tm = max(tm, t);

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
            {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
            }
        }
    }

    // step 3:Verify If any fresh Orange is left:

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] != 2)
            {
                cout << "-1" << endl;
                exit;
            }
        }
    }
    cout << tm;
}