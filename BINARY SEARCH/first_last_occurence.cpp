#include <iostream>
using namespace std;
int first_o(int arr[], int k, int n)
{
    int index = -1;
    int lb = 0;
    int ub = n - 1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (arr[mid] == k)
        {
            index = mid;
            ub = mid - 1;
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
    return index;
}
int last_o(int arr[], int k, int n)
{
    int index = -1;
    int lb = 0;
    int ub = n - 1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (arr[mid] == k)
        {
            index = mid;
            lb = mid + 1;
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
    return index;
}
int main()
{
    int arr[9] = {1, 2, 3, 4, 67, 67, 98, 324, 566};
    int k = 67;
    int n = sizeof(arr) / sizeof(arr[0]);
    int first = first_o(arr, k, n);
    int last = last_o(arr, k, n);
    cout << "Number at Indexs:" << first << " and " << last;
}