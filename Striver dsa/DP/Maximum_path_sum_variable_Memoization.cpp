#include <iostream>
#include <vector>
#include<climits>
using namespace std;
int solve(int i, int j, int m, int n, vector<vector<int>> &grid,vector<vector<int>>&dp_array)
{
    if (j < 0 || j >= n)return INT_MIN;

    if (i == 0)return grid[0][j];

    if(dp_array[i][j]!=-1)return dp_array[i][j];
    int up =solve(i - 1, j, m, n, grid,dp_array);
    int left_dai =solve(i - 1, j - 1, m, n, grid,dp_array);
    int right_dai =solve(i - 1, j + 1, m, n, grid,dp_array);

    int best= max(up, max(left_dai, right_dai));
    if(best==INT_MIN)return INT_MIN;

    return dp_array[i][j]=grid[i][j]+best;
}
int main()
{
    vector<vector<int>> grid = {{1, 2, 10, 4},
                                {100, 3, 2, 1},
                                {1, 1, 20, 2},
                                {1, 2, 2, 1}};
    int m = grid.size();    // row
    int n = grid[0].size(); // col
    vector<vector<int>>dp_array(m,vector<int>(n,-1));
    int ans=INT_MIN;
    for(int j=0;j<n;j++){
    ans = max(ans,solve(m - 1,j, m, n, grid,dp_array));
    }
    cout<<ans;
}