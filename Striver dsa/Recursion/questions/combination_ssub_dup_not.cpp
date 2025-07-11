#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
void sub(int k,int index,vector<int>&arr,vector<int>&ans,set<vector<int>>&res,int currsum){
    int n=arr.size();
    if(index==n){
        if(currsum==k){
         res.insert(ans);
        }
       return; 
    }
    
    ans.push_back(arr[index]);
    sub(k,index+1,arr,ans,res,currsum+arr[index]) ;  //to take...

    ans.pop_back();
    sub(k,index+1,arr,ans,res,currsum);  // to not take...

}
int main(){
     vector<int>arr={10,1,2,7,6,1,5};
     sort(arr.begin(),arr.end());
     vector<int>ans;
     int k=8;
     set<vector<int>>res;
     sub(k,0,arr,ans,res,0);

     for(auto it:res){
        cout<<"[";
        for(auto i:it){
         cout<<i<<" ";
        }cout<<"]\n";
     }
     return 0;
}