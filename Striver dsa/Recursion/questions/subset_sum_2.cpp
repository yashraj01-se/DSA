#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void sub(int index, vector<int> &arr, vector<int> &ans, vector<vector<int>> &res)
{
   int n=arr.size();
   res.push_back(ans);
   for(int i=index;i<n;i++){
    if(i>index && arr[i]==arr[i-1])continue;
   ans.push_back(arr[i]);
   sub(i+1,arr,ans,res);
   ans.pop_back();
   }
}
int main()
{
    vector<int> arr = {1,2,2,2,3,3};
    sort(arr.begin(), arr.end());
    vector<int> ans;
    vector<vector<int>> res;
    sub(0,arr,ans, res);

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