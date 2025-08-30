#include <iostream>
#include <vector>
using namespace std;
int robber(int start, int end, vector<int> &houses, vector<int> &dp_array)
{
    if (start == end)
        return houses[start];
    if (end < start)
        return 0;

    if (dp_array[end] != -1)
        return dp_array[end];
    int pick = houses[end] + robber(start, end - 2, houses, dp_array);
    int not_pick = 0 + robber(start, end - 1, houses, dp_array);

    return dp_array[end] = max(pick, not_pick);
}
int main()
{
    vector<int> houses = {1, 2, 3, 1};
    int n = houses.size();

    if (n == 1)
    {
        cout << houses[0];
        return 0;
    }

    vector<int> dp_array1(n, -1);
    int ans1 = robber(0, n - 2, houses, dp_array1);

    vector<int> dp_array2(n, -1);
    int ans2 = robber(1, n - 1, houses, dp_array2);

    cout << max(ans1, ans2);
}