#include<iostream>
#include<vector>
using namespace std;
int solve(int index,vector<int>&arr,int target){
    if(target==0)return 1;
    if(index==0)return arr[0]==target;
    
    int pick=0;
    int not_pick=solve(index-1,arr,target);
    if(arr[index]<=target){
        pick=solve(index-1,arr,target-arr[index]);
    }

    return pick+not_pick;
}
int main(){
   
    vector<int>arr={1,2,3};
    int n=arr.size();
    int k=3;
    int ans=solve(n-1,arr,k);
    cout<<ans;
}