#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void sub(int target, int index, vector<int> &arr, vector<int> &ans, vector<vector<int>> &res)
{
    int n = arr.size();
    if (target == 0)
    {
        res.push_back(ans);
        return;
    }

    for (int i = index; i < n; i++)
    {
        if (i > index && arr[i] == arr[i - 1])
            continue; // condition to skip that start of recursion...
        if (arr[i] > target)
            break;
        ans.push_back(arr[i]);
        sub(target - arr[i], i + 1, arr, ans, res); // to take...
        ans.pop_back();
    }
}
int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    sort(arr.begin(), arr.end());
    vector<int> ans;
    int k = 8;
    vector<vector<int>> res;
    sub(k, 0, arr, ans, res);

    for (auto it : res)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "]\n";
    }
    return 0;
}