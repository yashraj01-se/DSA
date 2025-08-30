#include <iostream>
#include <vector>
using namespace std;
int frog_jumps(int n, vector<int> &h, vector<int> &dp_array, int k)
{
    if (n == 0)
        return 0;
    int min_energy = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (n - j >= 0)
        {
            int jump = frog_jumps(n - j, h, dp_array, k) + abs(h[n] - h[n - j]);
            min_energy = min(min_energy, jump);
        }
        
    }
    return min_energy;
}
int main()
{
    vector<int> h = {30, 10, 60, 10, 60, 50};
    int n = h.size() - 1;
    vector<int> dp_array(n + 1, -1);
    int k = 5;
    int ans = frog_jumps(n, h, dp_array, k);
    cout << ans;
}