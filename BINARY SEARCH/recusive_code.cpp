#include <iostream>
using namespace std;
int BinarySearch(int arr[], int k, int lb, int ub)
{
    if (lb > ub)
        return -1;
    int mid = lb + (ub - lb) / 2;
    if (arr[mid] == k)
        return mid;
    else if (arr[mid] < k)
        return BinarySearch(arr, k, mid + 1, ub);
    else
        return BinarySearch(arr, k, lb, mid - 1);
}
int main()
{
    int arr[8] = {1, 2, 3, 4, 67, 98, 324, 566};
    int k = 324;
    int n = sizeof(arr) / sizeof(arr[0]);
    int lb = 0;
    int ub = n - 1;
    int res = BinarySearch(arr, k, lb, ub);
    cout << "Number at Index:" << res;
}