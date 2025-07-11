#include<iostream>
#include<vector>
using namespace std;
int sub(int k,int index,vector<int>&arr,vector<int>&ans,vector<vector<int>>&res,int currsum){
    int n=arr.size();
    if(index==n){
        if(currsum==k){
         res.push_back(ans);
         return 1;
        }
       return 0;  
    }
    
    ans.push_back(arr[index]);
    int l=sub(k,index+1,arr,ans,res,currsum+arr[index]);  //to take...

    ans.pop_back();
    int r=sub(k,index+1,arr,ans,res,currsum);  // to not take...

    return l+r;
}
int main(){
     vector<int>arr={9,12,1,0,3};
     vector<int>ans;
     int k=12;
     vector<vector<int>>res;
     int r=sub(k,0,arr,ans,res,0);

     for(auto it:res){
        cout<<"[";
        for(auto i:it){
         cout<<i<<" ";
        }cout<<"]\n";
     }
     cout<<"total count: "<< r;
     return 0;
}