#include<iostream>
#include<vector>
using namespace std;
bool sub(int k,int index,vector<int>&arr,vector<int>&ans,vector<vector<int>>&res,int currsum){
    int n=arr.size();
    if(index==n){
        if(currsum==k){
         res.push_back(ans);
         return true;
        }
       return false;  
    }
    
    ans.push_back(arr[index]);
    if(sub(k,index+1,arr,ans,res,currsum+arr[index]))return true ;  //to take...

    ans.pop_back();
    if(sub(k,index+1,arr,ans,res,currsum)) return true;  // to not take...

    return false;
}
int main(){
     vector<int>arr={9,12,1,0,3};
     vector<int>ans;
     int k=12;
     vector<vector<int>>res;
     sub(k,0,arr,ans,res,0);

     for(auto it:res){
        cout<<"[";
        for(auto i:it){
         cout<<i<<" ";
        }cout<<"]\n";
     }
     return 0;
}