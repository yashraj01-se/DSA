#include<iostream>
#include<vector>
using namespace std;
int solve(int index,vector<int>&arr,int target,vector<vector<int>>&dp){
    if(target==0)return 1;
    if(index==0)return arr[0]==target;
    
    if(dp[index][target]!=-1)return dp[index][target];
    int pick=0;
    int not_pick=solve(index-1,arr,target,dp);
    if(arr[index]<=target){
        pick=solve(index-1,arr,target-arr[index],dp);
    }

    return dp[index][target]=pick+not_pick;
}
int main(){
   
    vector<int>arr={1,2,3};
    int n=arr.size();
    int k=3;
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    int ans=solve(n-1,arr,k,dp);
    cout<<ans;
}