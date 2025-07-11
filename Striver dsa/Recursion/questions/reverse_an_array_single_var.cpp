#include <vector>
#include <iostream>
using namespace std;
vector<int> reverse(vector<int> arr,int i)
{
    int n=arr.size();
    if(i>=n/2)return arr;
    swap(arr[i],arr[n-i-1]);
    return reverse(arr,i+1);
}
int main()
{
    vector<int> arr = {1, 3, 2, 5, 4};
    int i = 0;
    vector<int> ans = reverse(arr, i);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}