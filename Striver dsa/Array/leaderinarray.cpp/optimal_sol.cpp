#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n=arr.size();
        int maxi=INT_MIN;
        vector<int>result;
        for(int i=n-1;i>=0;i--){
             if(arr[i]>maxi){
                maxi=arr[i];
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
