#include<iostream>
#include<vector>
using namespace std;
void sub(int index,vector<int>&arr,vector<int>&ans,vector<vector<int>>&res){
    
    int n=arr.size();
    if(index==n){
        res.push_back(ans);
        return;
    }
    
    ans.push_back(arr[index]);
    sub(index+1,arr,ans,res);  //to take...

    ans.pop_back();
    sub(index+1,arr,ans,res);  // to not take...
}
int main(){
     vector<int>arr={3,1,2};
     vector<int>ans;
     vector<vector<int>>res;
     sub(0,arr,ans,res);

     for(auto it:res){
        cout<<"[";
        for(auto i:it){
         cout<<i<<" ";
        }cout<<"]\n";
     }
     return 0;
}