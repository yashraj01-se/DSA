#include<iostream>
#include<vector>
using namespace std;
int solve(int index,vector<int>& arr, int target,vector<vector<int>>&dp_array){
      //since it ranges from 0-number..
      if(index==0){
        if(target==0 && arr[0]==0)return 2; //both pick and not pick.
        if(target==0 || arr[0]==target)return 1; //either pick or not pick;
        return 0;
      }

      if(dp_array[index][target]!=0)return dp_array[index][target];
      int pick=0;
      int notpick=solve(index-1,arr,target,dp_array);
      if(arr[index]<=target)pick=solve(index-1,arr,target-arr[index],dp_array);

      return dp_array[index][target]=pick+notpick;
}
int main(){
    vector<int> arr={5,2,5,1};
    int n=arr.size();
    int diff=3; 
    int total_sum=0;
    for(int i=0;i<n;i++){
        total_sum+=arr[i];
    } 
    int target=(total_sum-diff)/2;  
    if(total_sum<diff || (total_sum-diff)%2!=0)return 0;

    vector<vector<int>>dp_array(n,vector<int>(target+1,0));
    int ans=solve(n-1,arr,target,dp_array);
    cout<<ans;
}