#include<iostream>
#include<vector>
using namespace std;  
bool solve(int index,int target,vector<int>&arr,vector<vector<int>>dp_array){
    if(target==0)return true;
    if(index==0) return arr[0]==target;

    if(dp_array[index][target]!=-1)return dp_array[index][target];
    bool not_pick=solve(index-1,target,arr,dp_array);
    bool pick=false;
    if(target>=arr[index]){
        pick=solve(index-1,target-arr[index],arr,dp_array);
    }

    return dp_array[index][target]= not_pick || pick;
}  
int main(){
    vector<int> arr={1,2,3,4};
    int k=4;
    int n=arr.size();
    vector<vector<int>>dp_array(n,vector<int>(k+1,-1));
    bool ans=solve(n-1,k,arr,dp_array);
    if(ans){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
}