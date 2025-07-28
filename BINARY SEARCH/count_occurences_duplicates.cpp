#include <iostream>
using namespace std;
int first_o(int arr[],int n, int k)
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
        else if (arr[mid] > k)
        {
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return index;
}
int last_o(int arr[],int n, int k)
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
    int arr[7] = {1, 1, 1, 3, 4, 5, 5};
    int k = 1;
    int n=sizeof(arr)/sizeof(arr[0]);
    int start = first_o(arr,n,k);
    int last = last_o(arr,n,k);
    cout << last - start + 1;
}