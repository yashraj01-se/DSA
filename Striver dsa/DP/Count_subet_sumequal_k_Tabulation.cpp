#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &arr, int target, vector<vector<int>> &dp)
{
    for (int i = 0; i < arr.size(); i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= target)
        dp[0][arr[0]] = 1;

    int pick = 0;
    int not_pick = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j <= target; j++)
        {
            not_pick = dp[i - 1][j];
            if (arr[i] <= j)
            {
                pick = dp[i - 1][j - arr[i]];
                dp[i][j] = pick + not_pick;
            }
        }
    }

    return dp[arr.size() - 1][target];
}
int main()
{

    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int k = 3;
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    int ans = solve(arr, k, dp);
    cout << ans;
}