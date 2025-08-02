#include <iostream>
#include <vector>
using namespace std;
long maxi(vector<int> &piles)
{
    long maxu = INT_MIN;
    for (int i = 0; i < piles.size(); i++)
    {
        if (piles[i] > maxu)
        {
            maxu = piles[i];
        }
    }
    return maxu;
}
long cei(vector<int> &piles, int mid)
{
    long sum = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        int div = (piles[i] + mid - 1) / mid;
        sum += div;
    }
    return sum;
}
int main()
{
    vector<int> piles = {30,11,23,4,20};
    int h = 5;
    int lb = 1;
    int ub = maxi(piles);
    while (lb <= ub)
    {
        long mid = lb + (ub - lb) / 2;
        long sum = cei(piles, mid);
        if (sum > h)
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    cout << lb;
}