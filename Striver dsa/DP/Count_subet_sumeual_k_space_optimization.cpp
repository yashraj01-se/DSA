#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> &arr, int target, vector<int>&prev)
{
    vector<int>curr(target+1,0);
    prev[0]=curr[0]=1;
    if (arr[0] <= target) prev[arr[0]] = 1;

    int pick = 0;
    int not_pick = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j <= target; j++)
        {
            not_pick = prev[j];
            if (arr[i] <= j)
            {
                pick = prev[j - arr[i]];
            }
            curr[j] = pick + not_pick;
        }
        prev=curr;
    }

    return prev[target];
}
int main()
{

    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    int k = 3;
    vector<int>prev(k+1,0);
    int ans = solve(arr, k, prev);
    cout << ans;
}