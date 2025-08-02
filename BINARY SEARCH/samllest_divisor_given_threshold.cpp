#include <iostream>
#include <vector>
using namespace std;
int maxi(vector<int> &arr)
{
    int m = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > m)
        {
            m = arr[i];
        }
    }
    return m;
}
bool thres(vector<int> &arr, int threshold, int mid)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int div = (arr[i] + mid - 1) / mid; // ceil
        sum += div;
    }
    return sum <= threshold;
}
int smallestDivisor(vector<int> &arr, int threshold)
{
    int lb = 1;
    int ub = maxi(arr);
    int ans = 0;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (thres(arr, threshold, mid))
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
    vector<int> arr = {1, 2, 5, 9};
    int threshold = 6;
    int answer = smallestDivisor(arr, threshold);
    cout<<answer;
}