#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Ninja_max(int days, int last, vector<vector<int>> &points, vector<vector<int>> &dp_array)
{
    dp_array[0][0] = max(points[0][1], points[0][2]);
    dp_array[0][1] = max(points[0][0], points[0][2]);
    dp_array[0][2] = max(points[0][0], points[0][1]);
    dp_array[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for (int day= 1; day<= days; day++)
    {
        for (int last = 0; last <= 3; last++)
        {
            int maxi = 0;
            for (int ac = 0; ac <= 2; ac++)
            {
                if (ac != last)
                {
                    int point = points[day][ac] + dp_array[day - 1][ac];
                    maxi = max(maxi, point);
                }
            }
            dp_array[day][last] = maxi;
        }
    }
    return dp_array[days][3];
}
int main()
{
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int n = points.size();
    vector<vector<int>> dp_array(n, vector<int>(n + 1, -1));
    int ans = Ninja_max(n - 1, 3, points, dp_array);
    cout << ans;
}