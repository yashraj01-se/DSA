#include<iostream>
#include<vector>
using namespace std;  
bool solve(int index,int target,vector<int>&arr,vector<vector<int>>&dp_array){
    for(int i=0;i<arr.size();i++){
       dp_array[i][0]=true;
    }
    if(target>=arr[0]){
        dp_array[0][arr[0]]=true;
    }
   
    bool not_pick=false;
    bool pick=false;

    for(int i=1;i<arr.size();i++){
        for(int j=1;j<=target;j++){
            not_pick=dp_array[i-1][j];
            if(j>=arr[i]){
             pick=dp_array[i-1][j-arr[i]];
            }
            dp_array[i][j]=not_pick || pick;
        }
    }

    return dp_array[arr.size()-1][target];
}  
int main(){
    vector<int> arr={1,2,3,4};
    int k=4;
    int n=arr.size();
    vector<vector<int>>dp_array(n,vector<int>(k+1,-1));
    bool ans=solve(0,k,arr,dp_array);
    if(ans){
        cout<<"Found";
    }
    else{
        cout<<"Not Found";
    }
}