#include <iostream>
#include <set>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>nums={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>>ans;
    set<vector<int>>seen;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                        vector<int>f={nums[i],nums[j],nums[k],nums[l]};
                        seen.insert(f);
                    }
                }
            }
        }
    }
    for(auto& it:seen){
        ans.push_back(it);
    }

   for (auto& triplet : ans) {
    cout << "[";
    for (int num : triplet) {
        cout << num << " ";
    }
    cout << "]";
}
cout << endl;


}