#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int solve(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp_array)
{
    int left = 0;
    int up = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp_array[i][j] = grid[0][0];
            else
            {
                left = (j > 0) ? grid[i][j] + dp_array[i][j - 1] : INT_MAX;
                up = (i > 0) ? grid[i][j] + dp_array[i - 1][j] : INT_MAX;
                dp_array[i][j] = min(left, up);
            }
        }
    }

    return dp_array[m - 1][n - 1];
}
int main()
{
    vector<vector<int>> grid = {{5, 9, 6},
                                {11, 5, 2},
                                {4, 7, 1}};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp_array(m, vector<int>(n, -1));
    int ans = solve(0, 0, m, n, grid, dp_array);
    cout << ans;
}