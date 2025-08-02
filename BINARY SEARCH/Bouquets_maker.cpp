#include <iostream>
#include <vector>
using namespace std;
int maxi(vector<int> &bloomday)
{
    int m = INT_MIN;
    for (int i = 0; i < bloomday.size(); i++)
    {
        if (bloomday[i] > m)
        {
            m = bloomday[i];
        }
    }
    return m;
}
bool canmake(vector<int> &bloomday, int mid, int m, int k)
{
    int flower = 0;
    int bouquets = 0;
    for (int i = 0; i < bloomday.size(); i++)
    {
        if (bloomday[i] <= mid)
        {
            flower++;
            if (flower == k)
            {
                bouquets++;
                flower = 0; // new bouquets formation
            }
        }
        else
        {
            flower = 0; // checking for simultanious flowers...
        }
    }
    return bouquets >= m;
}
int bouquets_maker(vector<int> &bloomday, int m, int k)
{
    int lb = 0;
    int ub = maxi(bloomday);
    int ans = -1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (canmake(bloomday, mid, m, k))
        {
            ans = mid;
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> bloomday = {1, 10, 3, 10, 2}; // no of day flower will take to bloom respectively...
    int m = 3;                                // number of bouquets..
    int k = 1;                                // number of flower in each bouquets...
    int answer = bouquets_maker(bloomday, m, k);
    cout<<answer;
}