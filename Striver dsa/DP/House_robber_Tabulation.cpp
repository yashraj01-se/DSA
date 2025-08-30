#include<iostream>
#include<vector>
using namespace std;
int solve(int n,vector<int>&nums,vector<int>&dp_array){
    dp_array[0]=nums[0];
    if(n<0)return 0;
    if(n==1)return max(nums[1],nums[0]);
    
    for(int i=2;i<=n;i++){
        dp_array[i]=max(nums[i]+dp_array[i-2],0+dp_array[i-1]);
    }
    return dp_array[n];
}
int main(){
    vector<int>nums={1,2,3,1};
    int n=nums.size()-1;
    vector<int>dp_array(n+1,-1);
    int ans=solve(n,nums,dp_array);
    cout<<ans;
}