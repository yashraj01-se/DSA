#include <iostream>
#include <vector>
using namespace std;
int solve(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp_array)
{
    // Base Case:
    for (int j1 = 0; j1 < n; j1++)
    {
        for (int j2 = 0; j2 < n; j2++)
        {
            
                if (j1 == j2)
                {
                    dp_array[m-1][j1][j2] = grid[m - 1][j1];
                }
                else
                {
                    dp_array[m-1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
                }
           
        }
    }

    int val;
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                int maxi = INT_MIN;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        if((j1+dj1>=0 && j1+dj1<n) && (j2+dj2>=0 && j2+dj2<n)){
                        val = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                        val += dp_array[i+1][j1+dj1][j2+dj2];
                        maxi = max(maxi, val);
                        }
                        else{
                            val=INT_MIN;
                        }
                    }
                }
                dp_array[i][j1][j2]=maxi;
            }
            
        }
    }

    return dp_array[0][0][n-1];
}
int main()
{
    vector<vector<int>> grid = {{2, 3, 1, 2},
                                {3, 4, 2, 2},
                                {5, 6, 3, 5}};

    int m = grid.size();    // no of rows...
    int n = grid[0].size(); // no of cols...

    int ans = 0;
    vector<vector<vector<int>>> dp_array(m, vector<vector<int>>(n, vector<int>(n, -1)));

    ans = solve(0, 0, n - 1, m, n, grid, dp_array); //(i,j1,j2,grid);
    cout << ans;
}