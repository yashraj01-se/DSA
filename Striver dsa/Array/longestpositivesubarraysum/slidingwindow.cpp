#include <iostream>
using namespace std;

int main()
{
    int arr[9] = {1, 2, 3, 1, 1, 1, 4, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int i = 0, j = 0;
    int sum = 0;
    int maxlength = 0;

    while (i < n)
    {
        sum += arr[j];

        while (sum > k && i <= j)
        {
            sum -= arr[i];
            i++;
        }

        if (sum == k)
        {
            maxlength = max(maxlength, j - i + 1);
        }

        j++;
    }

    cout << maxlength;
    return 0;
}
