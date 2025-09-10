#include<iostream>
#include<vector>
using namespace std;
int solve(int index,vector<int>& arr, int target,vector<int>&prev){
      //since it ranges from 0-number..
    if (arr[0] == 0) prev[0] = 2;  
    else prev[0] = 1;

    if (arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;

    vector<int>curr(target+1,0);

      int pick=0;
      int notpick=0;
      for(int i=1;i<arr.size();i++){
        for(int j=0;j<=target;j++){
          notpick=prev[j];
          if(arr[i]<=j)pick=prev[j-arr[i]];
          curr[j]=pick+notpick;
        }
        prev=curr;
      }
     
      return prev[target];
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

    vector<int>prev(target+1,0);
    int ans=solve(n-1,arr,target,prev);
    cout<<ans;
}