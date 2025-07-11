#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum < target)
                {
                    k++;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    while (k < l && nums[k] == nums[k + 1])
                        k++;
                    while (k < l && nums[l] == nums[l - 1])
                        l--;
                    k++;
                    l--;
                }
            }
        }
    }
    for (auto &it : ans)
    {
        cout << "[";
        for (auto &i : it)
        {
            cout << i << " ";
        }
        cout << "]";
    }
}