#include <iostream>
using namespace std;
int main()
{
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        sum = 0;
        for (int j = i; j < 8; j++)
        {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    cout << maxi;
}