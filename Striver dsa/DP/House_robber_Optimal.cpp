#include<iostream>
#include<vector>
using namespace std;
int solve(int n,vector<int>&nums){
    if(n==0)return nums[0];
    if(n==1)return max(nums[1],nums[0]);
    if(n<0)return 0;

    int prev2=nums[0];
    int prev1=max(nums[0],nums[1]);
    int curr;
   
    for(int i=2;i<=n;i++){
        curr=max(nums[i]+prev2,0+prev1);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main(){
    vector<int>nums={1,2,3,1};
    int n=nums.size()-1;
    int ans=solve(n,nums);
    cout<<ans;
}