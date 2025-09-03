#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Ninja_max(int days, int last, vector<vector<int>> &points, vector<int> &prev)
{
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});

    for (int day= 1; day<= days; day++)
    {
        vector<int>temp(4,0);
        for (int last = 0; last <= 3; last++)
        {
            int maxi = 0;
            for (int ac = 0; ac <= 2; ac++)
            {
                if (ac != last)
                {
                    int point = points[day][ac] + prev[ac];
                    maxi = max(maxi, point);
                }
            }
            temp[last]= maxi;
        }
        prev=temp;
    }
    return prev[3];
}
int main()
{
    vector<vector<int>> points = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int n = points.size();
    vector<int>prev(n + 1, -1);
    int ans = Ninja_max(n - 1, 3, points, prev);
    cout << ans;
}