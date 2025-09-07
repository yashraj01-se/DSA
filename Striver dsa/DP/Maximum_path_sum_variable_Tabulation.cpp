#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int solve(vector<vector<int>> &grid, vector<vector<int>> &dp_array)
{
    int m=grid.size();
    int n=grid[0].size();
    
    for(int j=0;j<n;j++){
       dp_array[0][j]=grid[0][j];
    }

    for (int i = 1; i< m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = dp_array[i - 1][j];
            int left_dai =(j>0)?dp_array[i - 1][j - 1]:INT_MIN;
            int right_dai =(j<n)?dp_array[i - 1][j + 1]:INT_MIN;
            int best = max(up, max(left_dai, right_dai));
            if (best == INT_MIN)return INT_MIN;
            dp_array[i][j] = grid[i][j] + best;
        }
    }
    int ans=INT_MIN;
    for(int j=0;j<n;j++){
        ans=max(ans,dp_array[m-1][j]);
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid = {{1, 2, 10, 4},
                                {100, 3, 2, 1},
                                {1, 1, 20, 2},
                                {1, 2, 2, 1}};
    int m = grid.size();    // row
    int n = grid[0].size(); // col
    vector<vector<int>> dp_array(m, vector<int>(n, -1));
    int ans = INT_MIN;
    ans=solve(grid,dp_array);
    cout << ans;
}