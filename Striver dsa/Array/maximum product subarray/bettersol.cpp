#include <iostream>
using namespace std;
int main()
{
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int maxi = INT_MIN;
    int product = 1;
    for (int i = 0; i < 8; i++)
    {
        product = 1;
        for (int j = i; j < 8; j++)
        {
            product *= arr[j];
            maxi = max(maxi, product);
        }
    }
    cout << maxi;
}