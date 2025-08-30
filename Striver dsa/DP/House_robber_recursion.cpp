#include<iostream>
#include<vector>
using namespace std;
int solve(int n,vector<int>&nums){
    if(n==0)return nums[0];
    if(n<0)return 0;

    int pick=nums[n]+solve(n-2,nums);
    int not_pick=0+solve(n-1,nums);
    
    return max(pick,not_pick);
}
int main(){
    vector<int>nums={1,2,3,1};
    int n=nums.size()-1;
    int ans=solve(n,nums);
    cout<<ans;
}