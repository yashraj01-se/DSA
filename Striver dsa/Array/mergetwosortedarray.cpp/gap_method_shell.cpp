#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int arr1[4] = {2, 4, 5, 6};
    int arr2[4] = {1, 3, 7, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size = size1 + size2;
    int gap = ceil(float(size1 + size2) / 2);
    while (gap > 0)
    {
        int i = 0;
        int j = gap;
        while (j < size)
        {
            // if both the pointers are in arr1:
            if (i < size1 && j < size1)
            {
                if (arr1[i] > arr1[j])
                {
                    swap(arr1[i], arr1[j]);
                }
            }
            // if i is in arr1 and j is in arr2:
            else if (i < size1 && j >= size1)
            {
                if (arr1[i] > arr2[j - size1])
                {
                    swap(arr1[i], arr2[j - size1]);
                }
            }
            // if both the pointer are in arr2:
            else if (i >= size1 && j >= size1)
            {
                if (arr2[i - size1] > arr2[j - size1])
                {
                    swap(arr2[i - size1], arr2[j - size1]);
                }
            }
            i++;
            j++;
        }

        if (gap == 1)
            gap = 0;
        else
            gap = ceil((float)gap / 2);
    }
    cout << "arr1: ";
    for (int i = 0; i < 4; i++)
    {
        cout << arr1[i] << " ";
    }

    cout << "\narr2: ";
    for (int i = 0; i < 4; i++)
    {
        cout << arr2[i] << " ";
    }
}