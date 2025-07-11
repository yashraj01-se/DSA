#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive, negative, result;

        for (auto it : nums) {
            if (it > 0) {
                positive.push_back(it);
            } else {
                negative.push_back(it);
            }
        }

        for (int i = 0; i < positive.size(); i++) {
            result.push_back(positive[i]);
            result.push_back(negative[i]);
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
