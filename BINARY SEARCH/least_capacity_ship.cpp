#include <iostream>
#include <vector>
using namespace std;
int maxi(vector<int> &weights)
{
    int i = 0;
    int n = weights.size();
    int Maxi = INT_MIN;
    while (i < n - 1)
    {
        if (weights[i] > Maxi)
        {
            Maxi = weights[i];
            
        }
        i++;
    }
    return Maxi;
}
int suma(vector<int> &weights)
{
    int sum = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        sum += weights[i];
    }
    return sum;
}
bool canship(vector<int> &weights, int days, int mid)
{
    int count = 1; // days count...
    int sum = 0;   // per day ship capacity...
    bool ship = true;
    for (int i = 0; i < weights.size(); i++)
    {
        sum += weights[i];
        if (sum > mid)
        {
            count++;
            sum = 0;
            i = i - 1;
            if (count > days)
            {
                ship = false;
            }
        }
    }
    return ship;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int lb = maxi(weights);
    int ub = suma(weights);
    int ans = 0;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (canship(weights, days, mid))
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
    vector<int> weights = {3, 2, 2, 4, 1, 4};
    int days = 3;
    int answer = shipWithinDays(weights, days);
    cout << answer;
}