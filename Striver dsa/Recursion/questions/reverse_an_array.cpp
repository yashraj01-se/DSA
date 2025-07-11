#include <vector>
#include <iostream>
using namespace std;
vector<int> reverse(vector<int> arr, int i, int j)
{
    if (i >= j)
    {
        return arr;
    }
    swap(arr[i], arr[j]);
    return reverse(arr, i + 1, j - 1);
}
int main()
{
    vector<int> arr = {1, 3, 2, 5, 4};
    int i = 0;
    int j = arr.size()-1;
    vector<int> ans = reverse(arr, i, j);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}