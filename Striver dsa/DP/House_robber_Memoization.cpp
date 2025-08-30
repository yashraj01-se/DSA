#include<iostream>
#include<vector>
using namespace std;
int solve(int n,vector<int>&nums,vector<int>&dp_array){
    if(n==0)return nums[0];
    if(n<0)return 0;
    
    if(dp_array[n]!=-1)return dp_array[n];
    int pick=nums[n]+solve(n-2,nums,dp_array);
    int not_pick=0+solve(n-1,nums,dp_array);

    return dp_array[n]=max(pick,not_pick);
}
int main(){
    vector<int>nums={1,2,3,1};
    int n=nums.size()-1;
    vector<int>dp_array(n+1,-1);
    int ans=solve(n,nums,dp_array);
    cout<<ans;
}