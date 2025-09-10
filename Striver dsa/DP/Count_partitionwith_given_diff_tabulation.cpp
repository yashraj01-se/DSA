#include<iostream>
#include<vector>
using namespace std;
int solve(int index,vector<int>& arr, int target,vector<vector<int>>&dp_array){
      //since it ranges from 0-number..
    if (arr[0] == 0) dp_array[0][0] = 2;  
    else dp_array[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= target) dp_array[0][arr[0]] = 1;

      int pick=0;
      int notpick=0;
      for(int i=1;i<arr.size();i++){
        for(int j=0;j<=target;j++){
          notpick=dp_array[i-1][j];
          if(arr[i]<=j)pick=dp_array[i-1][j-arr[i]];
          dp_array[i][j]=pick+notpick;
        }
      }
     
      return dp_array[arr.size()-1][target];
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