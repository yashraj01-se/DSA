#include <iostream>
using namespace std;
bool search(int arr[], int n, int k)
{
    int lb = 0;
    int ub = n - 1;
    bool flag = false;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (arr[mid] == k)
        {
            flag = true;
            return flag;
        }
        if (arr[lb] == arr[mid] && arr[mid] == arr[ub])  // taking Advantage of the Scenario....
        {
            lb++;
            ub--;
        }
        else if (arr[mid] >= arr[lb])
        {
            if (arr[mid] > k && arr[lb] <= k)
            {
                ub = mid - 1;
            }
            else
            {
                lb = mid + 1;
            }
        }
        else
        {
            if (arr[mid] < k && arr[ub] >= k)
            {
                lb = mid + 1;
            }
            else
            {
                ub = mid - 1;
            }
        }
    }
    return flag;
}
int main()
{
    int arr[10] = {1, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    int k = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    bool searchindex = search(arr, n, k);
    if (searchindex)
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }
}