#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canplace(vector<int> &cows, int mid, int k)
{
    int cowcount = 1;
    int stall = cows[0];
    for (int i = 1; i < cows.size(); i++)
    {
        if (cows[i] - stall >= mid)
        {
            cowcount++;
            stall = cows[i];
            if (cowcount >= k)
                return true;
        }
    }
    return false;
}
int cowstalls(vector<int> &cows, int k)
{
    sort(cows.begin(), cows.end());
    int lb = 1;
    int ub = cows.back() - cows.front();
    int ans = 0;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (canplace(cows, mid, k))
        {
            ans = mid;
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> cows = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = cowstalls(cows, k);
    cout << ans;
}