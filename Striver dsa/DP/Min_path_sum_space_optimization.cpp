#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int solve(int i, int j, int m, int n, vector<vector<int>> &grid, vector<int>&prev)
{
    for (int i = 0; i < m; i++)
    {
        vector<int>curr(n,0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)curr[j]=grid[0][0];
            else
            {
                int left=(j>0)?curr[j-1]:INT_MAX;
                int up=(i>0)?prev[j]:INT_MAX;
                curr[j]=grid[i][j]+min(left,up);
            }
        }
        prev=curr;
    }

    return prev[n - 1];
}
int main()
{
    vector<vector<int>> grid = {{5, 9, 6},
                                {11, 5, 2},
                                {4, 7, 1}};
    int m = grid.size();
    int n = grid[0].size();
    vector<int>prev(n,0);
    int ans = solve(0, 0, m, n, grid,prev);
    cout << ans;
}