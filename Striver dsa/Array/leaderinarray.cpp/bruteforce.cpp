#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
         
        for (int i = 0; i < n; i++) {
            bool isLeader = true;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    isLeader = false;
                    break;
                }
            }
            if (isLeader) {
                result.push_back(arr[i]);
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    
    vector<int> leaders = sol.leaders(arr);
    
    cout << "Leaders in the array are: ";
    for (int num : leaders) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
