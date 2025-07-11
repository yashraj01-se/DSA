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
        set<int>hashing;
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
               int fourth=target-(nums[i]+nums[j]+nums[k]);
               if(hashing.find(fourth)!=hashing.end()){
                   vector<int>f={nums[i],nums[j],nums[k],fourth};
                   sort(f.begin(),f.end());
                   seen.insert(f);
               }
               hashing.insert(nums[k]);
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