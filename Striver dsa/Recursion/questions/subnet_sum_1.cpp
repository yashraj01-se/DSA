#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void sub(int index, vector<int> &arr, vector<int> &ans, vector<vector<int>> &res ,vector<int>&sums)
{
    int n=arr.size();
    int sum=0;
   if(index==n){
    res.push_back(ans);
   int i=0;
   while(i<ans.size()){
    sum+=ans[i];
    i++;
   }
   sums.push_back(sum);
    return;
   }
   ans.push_back(arr[index]);
   sub(index+1,arr,ans,res,sums);
   ans.pop_back();
   sub(index+1,arr,ans,res,sums);
}
int main()
{
    vector<int> arr = {3,1,2};
    sort(arr.begin(), arr.end());
    vector<int> ans;
    vector<vector<int>> res;
    vector<int>sums;
    sub(0,arr,ans, res,sums);

    for (auto it : res)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "]\n";
    }
    sort(sums.begin(),sums.end());
    cout<<"[";
    for(auto it:sums){
        cout<<it<<" ";
    }cout<<"]";
    return 0;
}