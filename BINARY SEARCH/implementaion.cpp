#include <iostream>
using namespace std;
int BinarySearch(int arr[], int n, int k)
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
        else if (arr[mid] < k)
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[8] = {1, 2, 3, 4, 67, 98, 324, 566};
    int k = 98;
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = BinarySearch(arr, n, k);
    cout << "Number at Index:" << res;
}