#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0){
              j++;
            }
            else if(sum>0){
              k--;
            }
            else{
                vector<int>temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                while(j<k && nums[j]==nums[j+1]) j++;
                while(j<k && nums[k]== nums[k-1])k--;
                j++;
                k--;
            }
        }
    }
    for(auto&it:ans){
        cout<<"[";
       for(auto&i:it){
        cout<<i<<" ";
       }cout<<"]";
    }
}