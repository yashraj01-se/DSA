#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //step 1:find the breaking point...
        int breaking_point=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breaking_point=i;
                break;
            }
        }
        //step 2:find the element just greater than index in the right hand side of index....
        if(breaking_point!=-1){
             for(int i=nums.size()-1;i>=breaking_point;i--){
                    if(nums[i]>nums[breaking_point]){
                         swap(nums[i],nums[breaking_point]);
                         break;
                    }
             }
        }
        //step 3: reverse the remaining part.....
        reverse(nums.begin()+breaking_point+1,nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    sol.nextPermutation(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
