#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    int arr[8] = {1, 1, 1, 2, 3, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int counter1 = 0;
    int counter2 = 0;
    int candidate1 = -1;
    int candidate2 = -1;
    int i = 0;
    while (i < n)
    {
        if (arr[i] == candidate1)
        {
            counter1++;
        }
        else if (arr[i] == candidate2)
        {
            counter2++;
        }
        
        else if (counter1 == 0 && arr[i] != candidate1)
        {
            candidate1 = arr[i];
            counter1 = 1;
        }
        else if (counter2 == 0 && arr[i] != candidate2)
        {
            candidate2 = arr[i];
            counter2 = 1;
        }
             else{
            counter1--;
            counter2--;
        }
         i++;
    }
       
        
    cout<<candidate1<<" "<<candidate2;
    }
   