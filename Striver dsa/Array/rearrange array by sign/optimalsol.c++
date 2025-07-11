#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>result(nums.size());
       int i=0;
       int positive=0;
       int negative=1;
       while(i<=nums.size()){
        if(nums[i]>0 && positive<nums.size()){
              result[positive]=nums[i];
              positive=positive+2;
        }
        else if(nums[i]<0 && negative<nums.size()){
             result[negative]=nums[i];
            negative=negative+2;
        }
        i++;
       }
       return result;

    }
};

int main() {
    vector<int> nums = {3, 1, -2, -5, 2, -4}; // Sample input
    Solution sol;
    vector<int> rearranged = sol.rearrangeArray(nums);

    cout << "Rearranged Array: ";
    for (int num : rearranged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
