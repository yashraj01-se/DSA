#include <iostream>
#include <vector>
using namespace std;
int median(int arr1[], int arr2[], int n, int m)
{
    vector<int> arr3;
    int count = 0;
    int i = 0;
    int j = 0;
    int size = n + m;
    int ind1 = size / 2;
    int ind2 = (size - 1) / 2;
    int ele1 = -1;
    int ele2 = -1;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            if (count == ind1)
                ele1 = arr1[i];
            if (count == ind2)
                ele2 = arr1[i];
            count++;
            i++;
        }
        else
        {
            if (count == ind1)
                ele1 = arr1[j];
            if (count == ind2)
                ele2 = arr1[j];
            count++;
            j++;
        }
    }
    while (i < n)
    {
        if (count == ind1)
            ele1 = arr1[i];
        if (count == ind2)
            ele2 = arr1[i];
        count++;
        i++;
    }
    while (j < m)
    {
        if (count == ind1)
            ele1 = arr1[j];
        if (count == ind2)
            ele2 = arr1[j];
        count++;
        j++;
    }
    if(size%2==1){
        return (ele1+ele2)/2;
    }
    else{
        return ele2/2;
    }
}
int main()
{
    int arr1[6] = {1, 3, 4, 7, 10, 12};
    int arr2[4] = {2, 3, 6, 15};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    int ans = median(arr1, arr2, n, m);
    cout << ans;
}