#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans;
    set<vector<int>>seen;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> triplet = {nums[i], nums[j], third};
                seen.insert(triplet);
            }
            hashset.insert(nums[j]);
        }
        
    }
    for(auto& it:seen){
        cout<<"[";
      for(auto& t:it){
          cout<<t<<" ";
      }cout<<"]";
    }
}