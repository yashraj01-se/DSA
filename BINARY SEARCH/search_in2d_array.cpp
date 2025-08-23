#include <iostream>
#include <vector>
using namespace std;
bool search(int arr[], int n, int num)
{
    bool flag = false;
    if (num < arr[0] || num > arr[n - 1])
    {
        return flag;
    }
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == num)
        {
            flag = true;
            break;
        }
        else if (arr[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return flag;
}
int main()
{
    int arr[3][4] = {{3, 4, 7, 9},
                     {12, 13, 16, 18},
                     {20, 21, 23, 29}};
    bool answer = false;
    int num = 23;
    int n = sizeof(arr[0]) / sizeof(arr[0][0]);
    for (int i = 0; i < 3; i++)
    {
        answer = search(arr[i], n, num);
        if(answer){
            cout<<"Number found";
            break;
        }
    }

}