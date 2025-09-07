#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int solve(vector<vector<int>> &grid, vector<int> &prev)
{
    int m=grid.size();
    int n=grid[0].size();

    for(int j=0;j<n;j++){
        prev[j]=grid[0][j];
    }

    for (int i = 1; i< m; i++)
    {
        vector<int>temp(n,0);
        for (int j = 0; j < n; j++)
        {
            int up = prev[j];
            int left_dai =(j>0)?prev[j - 1]:INT_MIN;
            int right_dai =(j<n)?prev[j + 1]:INT_MIN;
            int best = max(up, max(left_dai, right_dai));
            if (best == INT_MIN)return INT_MIN;
            temp[j]=grid[i][j]+best;
        }
        prev=temp;
    }
    int ans=INT_MIN;
    for(int j=0;j<n;j++){
        ans=max(ans,prev[j]);
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
    vector<int>prev(n,0);
    int ans = INT_MIN;
    ans=solve(grid,prev);
    cout << ans;
}