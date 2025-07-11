#include<iostream>
#include<vector>
using namespace std;
void sub(int target,int index,vector<int>&arr,vector<int>&ans,vector<vector<int>>&res){
    int n=arr.size();
    
    if(target==0){
        res.push_back(ans);
        return;
    }
    if(target<0||index==n)return;
    
    ans.push_back(arr[index]);
    sub(target-arr[index],index,arr,ans,res);  //to take... but multiple time...

    ans.pop_back();
    sub(target,index+1,arr,ans,res);  // to not take...

}
int main(){
     vector<int>arr={2,3,5};
     vector<int>ans;
     int target=8;
     vector<vector<int>>res;
     sub(target,0,arr,ans,res);

     for(auto it:res){
        cout<<"[";
        for(auto i:it){
         cout<<i<<" ";
        }cout<<"]\n";
     }
     return 0;
}