#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    sort(nums.begin(), nums.end());
    int counter = 0;
    int longest = 1;
    int lastsmaller = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] - 1 == lastsmaller)
        {
            counter++;
            lastsmaller = nums[i];
        }
        else if (nums[i] == lastsmaller)
        {
            // nothing to do;
        }
        else if (nums[i] != lastsmaller)
        {
            counter = 1;
            lastsmaller = nums[i];
        }
        longest = max(longest, counter);
    }
    cout << longest;
}