#include <iostream>
using namespace std;
int search(int arr[], int n, int k)
{
    int lb = 0;
    int ub = n - 1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (arr[mid] == k)
        {
            return mid;
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
    return -1;
}
int main()
{
    int arr[9] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int k = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    int searchindex = search(arr, n, k);
    cout << searchindex;
}